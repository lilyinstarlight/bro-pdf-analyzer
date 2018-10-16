# @TEST-EXEC: bro -Cr $TRACES/js.pcap %INPUT >output
# @TEST-EXEC: btest-diff output
event pdf_info(f: fa_file, info: PDF::Info) {
	print info$js;
}
