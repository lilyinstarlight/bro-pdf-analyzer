# @TEST-EXEC: bro -Cr $TRACES/version.pcap %INPUT >output
# @TEST-EXEC: btest-diff output
event pdf_info(f: fa_file, info: PDF::Info) {
	if (info?$ver)
		print info$ver;
}