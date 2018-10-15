#ifndef ANALYZER_PDF_H
#define ANALYZER_PDF_H

#include <file_analysis/File.h>

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
};

}

#endif
