# @TEST-EXEC: bro -Cr $TRACES/pdf.pcap %INPUT >output
# @TEST-EXEC: btest-diff output
event pdf_version(f: fa_file, ver: string) {
	print ver;
}
