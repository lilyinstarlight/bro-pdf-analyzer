# @TEST-EXEC: bro -Cr $TRACES/notify.pcap %INPUT
# @TEST-EXEC: btest-diff notice.log
@load Analyzer/PDF

redef PDF::MAX_SIZE: count = 1048576;
