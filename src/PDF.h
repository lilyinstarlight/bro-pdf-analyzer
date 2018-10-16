#ifndef ANALYZER_PDF_H
#define ANALYZER_PDF_H

#include <string>

#include <Val.h>

#include <file_analysis/Analyzer.h>
#include <file_analysis/File.h>

// fix macro collisions
#pragma push_macro("IsBool")
#undef IsBool
#pragma push_macro("IsString")
#undef IsString
#include <podofo.h>
#pragma pop_macro("IsString")
#pragma pop_macro("IsBool")

namespace file_analysis {

class PDF : public file_analysis::Analyzer {
	public:
		virtual ~PDF();

		static file_analysis::Analyzer * Instantiate(RecordVal * args, File * file) {
			return new PDF(args, file);
		}

		virtual bool DeliverStream(const u_char * data, uint64 len);
		virtual bool EndOfFile();

	protected:
		PDF(RecordVal * args, File * file);

		string pdf_data;

		PoDoFo::PdfMemDocument doc;
};

}

#endif
