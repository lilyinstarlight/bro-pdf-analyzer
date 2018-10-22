#include <file_analysis/Manager.h>

#include "PDF.h"

using namespace file_analysis;

PDF::PDF(RecordVal * args, File * file) : file_analysis::Analyzer(file_mgr->GetComponentTag("PDF"), args, file) {
	PoDoFo::PdfError::EnableDebug(false);
	PoDoFo::PdfError::EnableLogging(false);
}

PDF::~PDF() {
}

string PDF::getVersionString(PoDoFo::EPdfVersion version) const {
	switch (version) {
		case PoDoFo::ePdfVersion_1_0:
			return "1.0";

		case PoDoFo::ePdfVersion_1_1:
			return "1.1";

		case PoDoFo::ePdfVersion_1_2:
			return "1.2";

		case PoDoFo::ePdfVersion_1_3:
			return "1.3";

		case PoDoFo::ePdfVersion_1_4:
			return "1.4";

		case PoDoFo::ePdfVersion_1_5:
			return "1.5";

		case PoDoFo::ePdfVersion_1_6:
			return "1.6";

		case PoDoFo::ePdfVersion_1_7:
			return "1.7";
	}

	return "";
}

BifEnum::PDF::Error PDF::convertError(PoDoFo::EPdfError err) const {
		switch(err) {
			case PoDoFo::ePdfError_ErrOk:
				return BifEnum::PDF::ERR_OK;

			case PoDoFo::ePdfError_TestFailed:
				return BifEnum::PDF::TEST_FAILED;

			case PoDoFo::ePdfError_InvalidHandle:
				return BifEnum::PDF::INVALID_HANDLE;

			case PoDoFo::ePdfError_FileNotFound:
				return BifEnum::PDF::FILE_NOT_FOUND;

			case PoDoFo::ePdfError_InvalidDeviceOperation:
				return BifEnum::PDF::INVALID_DEVICE_OPERATION;

			case PoDoFo::ePdfError_UnexpectedEOF:
				return BifEnum::PDF::UNEXPECTED_EOF;

			case PoDoFo::ePdfError_OutOfMemory:
				return BifEnum::PDF::OUT_OF_MEMORY;

			case PoDoFo::ePdfError_ValueOutOfRange:
				return BifEnum::PDF::VALUE_OUT_OF_RANGE;

			case PoDoFo::ePdfError_InternalLogic:
				return BifEnum::PDF::INTERNAL_LOGIC;

			case PoDoFo::ePdfError_InvalidEnumValue:
				return BifEnum::PDF::INVALID_ENUM_VALUE;

			case PoDoFo::ePdfError_PageNotFound:
				return BifEnum::PDF::PAGE_NOT_FOUND;

			case PoDoFo::ePdfError_NoPdfFile:
				return BifEnum::PDF::NO_PDF_FILE;

			case PoDoFo::ePdfError_NoXRef:
				return BifEnum::PDF::NO_XREF;

			case PoDoFo::ePdfError_NoTrailer:
				return BifEnum::PDF::NO_TRAILER;

			case PoDoFo::ePdfError_NoNumber:
				return BifEnum::PDF::NO_NUMBER;

			case PoDoFo::ePdfError_NoObject:
				return BifEnum::PDF::NO_OBJECT;

			case PoDoFo::ePdfError_NoEOFToken:
				return BifEnum::PDF::NO_EOF_TOKEN;

			case PoDoFo::ePdfError_InvalidTrailerSize:
				return BifEnum::PDF::INVALID_TRAILER_SIZE;

			case PoDoFo::ePdfError_InvalidLinearization:
				return BifEnum::PDF::INVALID_LINEARIZATION;

			case PoDoFo::ePdfError_InvalidDataType:
				return BifEnum::PDF::INVALID_DATA_TYPE;

			case PoDoFo::ePdfError_InvalidXRef:
				return BifEnum::PDF::INVALID_XREF;

			case PoDoFo::ePdfError_InvalidXRefStream:
				return BifEnum::PDF::INVALID_XREF_STREAM;

			case PoDoFo::ePdfError_InvalidXRefType:
				return BifEnum::PDF::INVALID_XREF_TYPE;

			case PoDoFo::ePdfError_InvalidPredictor:
				return BifEnum::PDF::INVALID_PREDICTOR;

			case PoDoFo::ePdfError_InvalidStrokeStyle:
				return BifEnum::PDF::INVALID_STROKE_STYLE;

			case PoDoFo::ePdfError_InvalidHexString:
				return BifEnum::PDF::INVALID_HEX_STRING;

			case PoDoFo::ePdfError_InvalidStream:
				return BifEnum::PDF::INVALID_STREAM;

			case PoDoFo::ePdfError_InvalidStreamLength:
				return BifEnum::PDF::INVALID_STREAM_LENGTH;

			case PoDoFo::ePdfError_InvalidKey:
				return BifEnum::PDF::INVALID_KEY;

			case PoDoFo::ePdfError_InvalidName:
				return BifEnum::PDF::INVALID_NAME;

			case PoDoFo::ePdfError_InvalidEncryptionDict:
				return BifEnum::PDF::INVALID_ENCRYPTION_DICT;

			case PoDoFo::ePdfError_InvalidPassword:
				return BifEnum::PDF::INVALID_PASSWORD;

			case PoDoFo::ePdfError_InvalidFontFile:
				return BifEnum::PDF::INVALID_FONT_FILE;

			case PoDoFo::ePdfError_InvalidContentStream:
				return BifEnum::PDF::INVALID_CONTENT_STREAM;

			case PoDoFo::ePdfError_UnsupportedFilter:
				return BifEnum::PDF::UNSUPPORTED_FILTER;

			case PoDoFo::ePdfError_UnsupportedFontFormat:
				return BifEnum::PDF::UNSUPPORTED_FONT_FORMAT;

			case PoDoFo::ePdfError_ActionAlreadyPresent:
				return BifEnum::PDF::ACTION_ALREADY_PRESENT;

			case PoDoFo::ePdfError_WrongDestinationType:
				return BifEnum::PDF::WRONG_DESTINATION_TYPE;

			case PoDoFo::ePdfError_MissingEndStream:
				return BifEnum::PDF::MISSING_END_STREAM;

			case PoDoFo::ePdfError_Date:
				return BifEnum::PDF::DATE;

			case PoDoFo::ePdfError_Flate:
				return BifEnum::PDF::FLATE;

			case PoDoFo::ePdfError_FreeType:
				return BifEnum::PDF::FREETYPE;

			case PoDoFo::ePdfError_SignatureError:
				return BifEnum::PDF::SIGNATURE_ERROR;

			case PoDoFo::ePdfError_MutexError:
				return BifEnum::PDF::MUTEX_ERROR;

			case PoDoFo::ePdfError_UnsupportedImageFormat:
				return BifEnum::PDF::UNSUPPORTED_IMAGE_FORMAT;

			case PoDoFo::ePdfError_CannotConvertColor:
				return BifEnum::PDF::CANNOT_CONVERT_COLOR;

			case PoDoFo::ePdfError_NotImplemented:
				return BifEnum::PDF::NOT_IMPLEMENTED;

			case PoDoFo::ePdfError_DestinationAlreadyPresent:
				return BifEnum::PDF::DESTINATION_ALREADY_PRESENT;

			case PoDoFo::ePdfError_ChangeOnImmutable:
				return BifEnum::PDF::CHANGE_ON_IMMUTABLE;

#if PODOFO_MAJOR > 0 || (PODOFO_MAJOR == 0 && PODOFO_MINOR > 9) || (PODOFO_MAJOR == 0 && PODOFO_MINOR == 9 && PODOFO_REVISION >= 5)
			case PoDoFo::ePdfError_NotCompiled:
				return BifEnum::PDF::NOT_COMPILED;

			case PoDoFo::ePdfError_BrokenFile:
				return BifEnum::PDF::BROKEN_FILE;

			case PoDoFo::ePdfError_OutlineItemAlreadyPresent:
				return BifEnum::PDF::OUTLINE_ITEM_ALREADY_PRESENT;

			case PoDoFo::ePdfError_NotLoadedForUpdate:
				return BifEnum::PDF::NOT_LOADED_FOR_UPDATE;

			case PoDoFo::ePdfError_CannotEncryptedForUpdate:
				return BifEnum::PDF::CANNOT_ENCRYPTED_FOR_UPDATE;
#endif

			case PoDoFo::ePdfError_Unknown:
				return BifEnum::PDF::UNKNOWN;
		}

		return BifEnum::PDF::UNKNOWN;
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
#if PODOFO_MAJOR > 0 || (PODOFO_MAJOR == 0 && PODOFO_MINOR > 9) || (PODOFO_MAJOR == 0 && PODOFO_MINOR == 9 && PODOFO_REVISION >= 6)
		doc.LoadFromBuffer(reinterpret_cast<const char *>(pdf_data.data()), pdf_data.size());
#else
		doc.Load(reinterpret_cast<const char *>(pdf_data.data()), pdf_data.size());
#endif
	}
	catch (const PoDoFo::PdfError & err) {
		BifEvent::generate_pdf_error((analyzer::Analyzer *)this, GetFile()->GetVal()->Ref(), new EnumVal(convertError(err.GetError()), BifType::Enum::PDF::Error));
	}

	if (!doc.IsLoaded())
		return false;

	PoDoFo::PdfNamesTree * names = doc.GetNamesTree();

	PoDoFo::PdfDictionary emb_dict;
	names->ToDictionary(PoDoFo::PdfName("EmbeddedFiles"), emb_dict);
	bool embedded = !emb_dict.GetKeys().empty();

	PoDoFo::PdfDictionary js_dict;
	names->ToDictionary(PoDoFo::PdfName("JavaScript"), js_dict);
	bool javascript = !js_dict.GetKeys().empty();

	TypeList * tl = new TypeList(BifType::Record::PDF::Extension);
	tl->Append(BifType::Record::PDF::Extension);
	TableVal * extensions = new TableVal(new SetType(tl, 0));

	for (const PoDoFo::PdfExtension & ext : doc.GetPdfExtensions()) {
		RecordVal * extension = new RecordVal(BifType::Record::PDF::Extension);

		extension->Assign(0, new StringVal(ext.getNamespace()));
		extension->Assign(1, new StringVal(getVersionString(ext.getBaseVersion())));
		extension->Assign(2, new Val(ext.getLevel(), TYPE_INT));

		extensions->Assign(extension, nullptr);
	}

	RecordVal * info = new RecordVal(BifType::Record::PDF::Info);

	info->Assign(0, new StringVal(getVersionString(doc.GetPdfVersion())));
	info->Assign(1, new Val(doc.GetPageCount(), TYPE_COUNT));
	info->Assign(2, new Val(embedded, TYPE_BOOL));
	info->Assign(3, new Val(javascript, TYPE_BOOL));
	info->Assign(4, new Val(doc.GetEncrypted(), TYPE_BOOL));
	info->Assign(5, extensions);

	BifEvent::generate_pdf_info((analyzer::Analyzer *)this, GetFile()->GetVal()->Ref(), info);

	return true;
}
