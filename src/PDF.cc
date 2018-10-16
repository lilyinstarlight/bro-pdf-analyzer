#include <file_analysis/Manager.h>

#include "PDF.h"

#include "pdf.bif.h"

using namespace file_analysis;

PDF::PDF(RecordVal * args, File * file) : file_analysis::Analyzer(file_mgr->GetComponentTag("PDF"), args, file) {
	PoDoFo::PdfError::EnableDebug(false);
	PoDoFo::PdfError::EnableLogging(false);
}

PDF::~PDF() {
}

bool PDF::DeliverStream(const u_char * data, uint64 len) {
	pdf_data.append(reinterpret_cast<const char *>(data), len);

	return true;
}

bool PDF::EndOfFile() {
	try {
		doc.LoadFromBuffer(reinterpret_cast<const char *>(pdf_data.data()), pdf_data.size());

		string ver;

		switch (doc.GetPdfVersion()) {
			case PoDoFo::ePdfVersion_1_0:
				ver = "1.0";
				break;

			case PoDoFo::ePdfVersion_1_1:
				ver = "1.1";
				break;

			case PoDoFo::ePdfVersion_1_2:
				ver = "1.2";
				break;

			case PoDoFo::ePdfVersion_1_3:
				ver = "1.3";
				break;

			case PoDoFo::ePdfVersion_1_4:
				ver = "1.4";
				break;

			case PoDoFo::ePdfVersion_1_5:
				ver = "1.5";
				break;

			case PoDoFo::ePdfVersion_1_6:
				ver = "1.6";
				break;

			case PoDoFo::ePdfVersion_1_7:
				ver = "1.7";
				break;

			default:
				ver = "UNK";
				break;
		}

		BifEvent::generate_pdf_version((analyzer::Analyzer *)this, GetFile()->GetVal()->Ref(), new StringVal(ver));
	}
	catch (const PoDoFo::PdfError & e) {
		reporter->Error("could not read PDF: %s", e.what());

		return false;
	}

	return true;
}
