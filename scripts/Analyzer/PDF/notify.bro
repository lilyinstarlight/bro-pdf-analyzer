@load base/frameworks/files
@load base/frameworks/notice

module PDF;

export {
	redef enum Notice::Type += {
		## Raised when a PDF over
		## a certain size is found.
		PDF_Too_Large,

		## Raised when a PDF with
		## an error is found.
		PDF_Error,

		## Raised when a PDF with
		## JavaScript is found.
		PDF_JavaScript_Found,
	};
}

event pdf_too_large(f: fa_file) {
	if (f?$conns) {
		for (idx in f$conns) {
			NOTICE([$note=PDF_Too_Large, $msg=fmt("PDF found that is too large to analyze"), $conn=f$conns[idx]]);

			break;
		}
	}
	else {
		NOTICE([$note=PDF_Too_Large, $msg=fmt("PDF found that is too large to analyze")]);
	}
}

event pdf_error(f: fa_file, e: PDF::Error) {
	if (f?$conns) {
		for (idx in f$conns) {
			NOTICE([$note=PDF_Error, $msg=fmt("PDF found with an error %s", e), $conn=f$conns[idx]]);

			break;
		}
	}
	else {
		NOTICE([$note=PDF_Error, $msg=fmt("PDF found with an error %s", e)]);
	}
}

event pdf_info(f: fa_file, info: Info) {
	if (info$javascript) {
		if (f?$conns) {
			for (idx in f$conns) {
				if (f$info?$filename)
					NOTICE([$note=PDF_JavaScript_Found, $msg=fmt("JavaScript found in PDF named %s", f$info$filename), $conn=f$conns[idx]]);
				else
					NOTICE([$note=PDF_JavaScript_Found, $msg=fmt("JavaScript found in PDF"), $conn=f$conns[idx]]);

				break;
			}
		}
		else {
			if (f$info?$filename)
				NOTICE([$note=PDF_JavaScript_Found, $msg=fmt("JavaScript found in PDF named %s", f$info$filename)]);
			else
				NOTICE([$note=PDF_JavaScript_Found, $msg=fmt("JavaScript found in PDF")]);
		}
	}
}
