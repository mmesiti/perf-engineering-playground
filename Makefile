callgraph-test-sleep-scorep: callgraph-test.c 
	scorep gcc -DACTIVITY=sleep -o $@ $<

callgraph-test-busy-scorep: callgraph-test.c 
	scorep gcc -DACTIVITY=keeping_cpu_busy -o $@ $<

callgraph-test-busy-gprof: callgraph-test.c 
	gcc -pg -DACTIVITY=keeping_cpu_busy -o $@ $<

gmon.out: callgraph-test-busy-gprof
	./$<

gprof-busy: callgraph-test-busy-gprof gmon.out
	gprof $< | tee gprof-busy

callgraph-test-busy: callgraph-test.c 
	gcc -DACTIVITY=keeping_cpu_busy -g -o $@ $<

callgraph-test-sleep: callgraph-test.c 
	gcc -DACTIVITY=sleep -g -o $@ $<

busy.perf.data: callgraph-test-busy Makefile
	perf record -g ./$<
	mv perf.data busy.perf.data

sleep.perf.data: callgraph-test-sleep
	perf record --call-graph=fp ./$<
	mv perf.data sleep.perf.data
