# @TEST-EXEC: bro -Cr $TRACES/info.pcap %INPUT >output
# @TEST-EXEC: btest-diff output
event pdf_info(f: fa_file, info: PDF::Info) {
	if (info?$version)
		print info$version;

	print info$pages;
	print info$embedded;
	print info$javascript;
}
