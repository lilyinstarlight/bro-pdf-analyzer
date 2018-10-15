#include <file_analysis/Manager.h>

#include "PDF.h"

#include "pdf.bif.h"

using namespace file_analysis;

PDF::PDF(RecordVal * args, File * file) : file_analysis::Analyzer(file_mgr->GetComponentTag("PDF"), args, file) {
}

PDF::~PDF() {
}

bool PDF::DeliverStream(const u_char * data, uint64 len) {
	return true;
}

bool PDF::EndOfFile() {
	BifEvent::generate_pdf_version((analyzer::Analyzer *)this, GetFile()->GetVal()->Ref(), new StringVal("1.5"));

	return true;
}
