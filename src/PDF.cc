#include <file_analysis/Manager.h>

#include "PDF.h"

#include "events.bif.h"
#include "pdf.bif.h"

using namespace file_analysis;

PDF::PDF(RecordVal * args, File * file) : file_analysis::Analyzer(file_mgr->GetComponentTag("PDF"), args, file) {
	PoDoFo::PdfError::EnableDebug(false);
	PoDoFo::PdfError::EnableLogging(false);
}

PDF::~PDF() {
}

bool PDF::DeliverStream(const u_char * data, uint64 len) {
	if (pdf_data.size() + len > BifConst::PDF::MAX_SIZE) {
		BifEvent::generate_pdf_too_large((analyzer::Analyzer *)this, GetFile()->GetVal()->Ref());

		return false;
	}

	pdf_data.append(reinterpret_cast<const char *>(data), len);

	return true;
}

bool PDF::EndOfFile() {
	try {
		doc.LoadFromBuffer(reinterpret_cast<const char *>(pdf_data.data()), pdf_data.size());

		string version;

		switch (doc.GetPdfVersion()) {
			case PoDoFo::ePdfVersion_1_0:
				version = "1.0";
				break;

			case PoDoFo::ePdfVersion_1_1:
				version = "1.1";
				break;

			case PoDoFo::ePdfVersion_1_2:
				version = "1.2";
				break;

			case PoDoFo::ePdfVersion_1_3:
				version = "1.3";
				break;

			case PoDoFo::ePdfVersion_1_4:
				version = "1.4";
				break;

			case PoDoFo::ePdfVersion_1_5:
				version = "1.5";
				break;

			case PoDoFo::ePdfVersion_1_6:
				version = "1.6";
				break;

			case PoDoFo::ePdfVersion_1_7:
				version = "1.7";
				break;
		}

		PoDoFo::PdfNamesTree * names = doc.GetNamesTree();

		PoDoFo::PdfDictionary emb_dict;
		names->ToDictionary(PoDoFo::PdfName("EmbeddedFiles"), emb_dict);
		bool embedded = !emb_dict.GetKeys().empty();

		PoDoFo::PdfDictionary js_dict;
		names->ToDictionary(PoDoFo::PdfName("JavaScript"), js_dict);
		bool javascript = !js_dict.GetKeys().empty();

		RecordVal * info = new RecordVal(BifType::Record::PDF::Info);

		if (!version.empty())
			info->Assign(0, new StringVal(version));

		info->Assign(1, new Val(doc.GetPageCount(), TYPE_COUNT));
		info->Assign(2, new Val(embedded, TYPE_BOOL));
		info->Assign(3, new Val(javascript, TYPE_BOOL));

		BifEvent::generate_pdf_info((analyzer::Analyzer *)this, GetFile()->GetVal()->Ref(), info);
	}
	catch (const PoDoFo::PdfError & e) {
		BifEnum::PDF::Error err;

		switch(e.GetError()) {
			case PoDoFo::ePdfError_ErrOk:
				err = BifEnum::PDF::ERR_OK;
				break;

			case PoDoFo::ePdfError_TestFailed:
				err = BifEnum::PDF::TEST_FAILED;
				break;

			case PoDoFo::ePdfError_InvalidHandle:
				err = BifEnum::PDF::INVALID_HANDLE;
				break;

			case PoDoFo::ePdfError_FileNotFound:
				err = BifEnum::PDF::FILE_NOT_FOUND;
				break;

			case PoDoFo::ePdfError_InvalidDeviceOperation:
				err = BifEnum::PDF::INVALID_DEVICE_OPERATION;
				break;

			case PoDoFo::ePdfError_UnexpectedEOF:
				err = BifEnum::PDF::UNEXPECTED_EOF;
				break;

			case PoDoFo::ePdfError_OutOfMemory:
				err = BifEnum::PDF::OUT_OF_MEMORY;
				break;

			case PoDoFo::ePdfError_ValueOutOfRange:
				err = BifEnum::PDF::VALUE_OUT_OF_RANGE;
				break;

			case PoDoFo::ePdfError_InternalLogic:
				err = BifEnum::PDF::INTERNAL_LOGIC;
				break;

			case PoDoFo::ePdfError_InvalidEnumValue:
				err = BifEnum::PDF::INVALID_ENUM_VALUE;
				break;

			case PoDoFo::ePdfError_PageNotFound:
				err = BifEnum::PDF::PAGE_NOT_FOUND;
				break;

			case PoDoFo::ePdfError_NoPdfFile:
				err = BifEnum::PDF::NO_PDF_FILE;
				break;

			case PoDoFo::ePdfError_NoXRef:
				err = BifEnum::PDF::NO_XREF;
				break;

			case PoDoFo::ePdfError_NoTrailer:
				err = BifEnum::PDF::NO_TRAILER;
				break;

			case PoDoFo::ePdfError_NoNumber:
				err = BifEnum::PDF::NO_NUMBER;
				break;

			case PoDoFo::ePdfError_NoObject:
				err = BifEnum::PDF::NO_OBJECT;
				break;

			case PoDoFo::ePdfError_NoEOFToken:
				err = BifEnum::PDF::NO_EOF_TOKEN;
				break;

			case PoDoFo::ePdfError_InvalidTrailerSize:
				err = BifEnum::PDF::INVALID_TRAILER_SIZE;
				break;

			case PoDoFo::ePdfError_InvalidLinearization:
				err = BifEnum::PDF::INVALID_LINEARIZATION;
				break;

			case PoDoFo::ePdfError_InvalidDataType:
				err = BifEnum::PDF::INVALID_DATA_TYPE;
				break;

			case PoDoFo::ePdfError_InvalidXRef:
				err = BifEnum::PDF::INVALID_XREF;
				break;

			case PoDoFo::ePdfError_InvalidXRefStream:
				err = BifEnum::PDF::INVALID_XREF_STREAM;
				break;

			case PoDoFo::ePdfError_InvalidXRefType:
				err = BifEnum::PDF::INVALID_XREF_TYPE;
				break;

			case PoDoFo::ePdfError_InvalidPredictor:
				err = BifEnum::PDF::INVALID_PREDICTOR;
				break;

			case PoDoFo::ePdfError_InvalidStrokeStyle:
				err = BifEnum::PDF::INVALID_STROKE_STYLE;
				break;

			case PoDoFo::ePdfError_InvalidHexString:
				err = BifEnum::PDF::INVALID_HEX_STRING;
				break;

			case PoDoFo::ePdfError_InvalidStream:
				err = BifEnum::PDF::INVALID_STREAM;
				break;

			case PoDoFo::ePdfError_InvalidStreamLength:
				err = BifEnum::PDF::INVALID_STREAM_LENGTH;
				break;

			case PoDoFo::ePdfError_InvalidKey:
				err = BifEnum::PDF::INVALID_KEY;
				break;

			case PoDoFo::ePdfError_InvalidName:
				err = BifEnum::PDF::INVALID_NAME;
				break;

			case PoDoFo::ePdfError_InvalidEncryptionDict:
				err = BifEnum::PDF::INVALID_ENCRYPTION_DICT;
				break;

			case PoDoFo::ePdfError_InvalidPassword:
				err = BifEnum::PDF::INVALID_PASSWORD;
				break;

			case PoDoFo::ePdfError_InvalidFontFile:
				err = BifEnum::PDF::INVALID_FONT_FILE;
				break;

			case PoDoFo::ePdfError_InvalidContentStream:
				err = BifEnum::PDF::INVALID_CONTENT_STREAM;
				break;

			case PoDoFo::ePdfError_UnsupportedFilter:
				err = BifEnum::PDF::UNSUPPORTED_FILTER;
				break;

			case PoDoFo::ePdfError_UnsupportedFontFormat:
				err = BifEnum::PDF::UNSUPPORTED_FONT_FORMAT;
				break;

			case PoDoFo::ePdfError_ActionAlreadyPresent:
				err = BifEnum::PDF::ACTION_ALREADY_PRESENT;
				break;

			case PoDoFo::ePdfError_WrongDestinationType:
				err = BifEnum::PDF::WRONG_DESTINATION_TYPE;
				break;

			case PoDoFo::ePdfError_MissingEndStream:
				err = BifEnum::PDF::MISSING_END_STREAM;
				break;

			case PoDoFo::ePdfError_Date:
				err = BifEnum::PDF::DATE;
				break;

			case PoDoFo::ePdfError_Flate:
				err = BifEnum::PDF::FLATE;
				break;

			case PoDoFo::ePdfError_FreeType:
				err = BifEnum::PDF::FREETYPE;
				break;

			case PoDoFo::ePdfError_SignatureError:
				err = BifEnum::PDF::SIGNATURE_ERROR;
				break;

			case PoDoFo::ePdfError_MutexError:
				err = BifEnum::PDF::MUTEX_ERROR;
				break;

			case PoDoFo::ePdfError_UnsupportedImageFormat:
				err = BifEnum::PDF::UNSUPPORTED_IMAGE_FORMAT;
				break;

			case PoDoFo::ePdfError_CannotConvertColor:
				err = BifEnum::PDF::CANNOT_CONVERT_COLOR;
				break;

			case PoDoFo::ePdfError_NotImplemented:
				err = BifEnum::PDF::NOT_IMPLEMENTED;
				break;

			case PoDoFo::ePdfError_DestinationAlreadyPresent:
				err = BifEnum::PDF::DESTINATION_ALREADY_PRESENT;
				break;

			case PoDoFo::ePdfError_ChangeOnImmutable:
				err = BifEnum::PDF::CHANGE_ON_IMMUTABLE;
				break;

#if PODOFO_MAJOR >= 0 || (PODOFO_MAJOR == 0 && PODOFO_MINOR >= 9) || (PODOFO_MAJOR == 0 && PODOFO_MINOR == 9 && PODOFO_REVISION >= 5)
			case PoDoFo::ePdfError_NotCompiled:
				err = BifEnum::PDF::NOT_COMPILED;
				break;

			case PoDoFo::ePdfError_BrokenFile:
				err = BifEnum::PDF::BROKEN_FILE;
				break;

			case PoDoFo::ePdfError_OutlineItemAlreadyPresent:
				err = BifEnum::PDF::OUTLINE_ITEM_ALREADY_PRESENT;
				break;

			case PoDoFo::ePdfError_NotLoadedForUpdate:
				err = BifEnum::PDF::NOT_LOADED_FOR_UPDATE;
				break;

			case PoDoFo::ePdfError_CannotEncryptedForUpdate:
				err = BifEnum::PDF::CANNOT_ENCRYPTED_FOR_UPDATE;
				break;
#endif

			case PoDoFo::ePdfError_Unknown:
				err = BifEnum::PDF::UNKNOWN;
				break;
		}

		BifEvent::generate_pdf_error((analyzer::Analyzer *)this, GetFile()->GetVal()->Ref(), new EnumVal(err, BifType::Enum::PDF::Error));

		return false;
	}

	return true;
}
