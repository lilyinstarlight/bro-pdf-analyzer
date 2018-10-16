# @TEST-EXEC: bro -Cr $TRACES/notify.pcap %INPUT
# @TEST-EXEC: btest-diff notice.log
@load Analyzer/PDF
