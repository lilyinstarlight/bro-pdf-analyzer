@load base/frameworks/files
@load base/frameworks/notice

module PDF;

export {
	redef enum Notice::Type += {
		## Raised when a PDF with
		## JavaScript is found.
		PDF_JavaScript_Found,
	};
}

event pdf_info(f: fa_file, info: Info) {
	if (info$js) {
		if (f?$conns) {
			for (idx in f$conns) {
				if (f$info?$filename)
					NOTICE([$note=PDF_JavaScript_Found, $msg=fmt("JavaScript found in PDF named %s.", f$info$filename), $conn=f$conns[idx]]);
				else
					NOTICE([$note=PDF_JavaScript_Found, $msg=fmt("JavaScript found in PDF."), $conn=f$conns[idx]]);

				break;
			}
		}
		else {
			if (f$info?$filename)
				NOTICE([$note=PDF_JavaScript_Found, $msg=fmt("JavaScript found in PDF named %s.", f$info$filename)]);
			else
				NOTICE([$note=PDF_JavaScript_Found, $msg=fmt("JavaScript found in PDF.")]);
		}
	}
}
