CXX=g++
CFLAGS=-I.

SDIR=./structs
ODIR=./obj
BINDIR=./bin

$(ODIR)/utils.o: utils.cpp utils.h
	$(CXX) -c -o $@ $< $(CFLAGS)

$(ODIR)/heap.o: $(SDIR)/heap.cpp $(SDIR)/heap.h
	$(CXX) -c -o $@ $< $(CFLAGS)

$(ODIR)/linked_list.o: $(SDIR)/linked_list.cpp $(SDIR)/linked_list.h
	$(CXX) -c -o $@ $< $(CFLAGS)

$(ODIR)/ll_stack.o: $(SDIR)/ll_stack.cpp $(SDIR)/ll_stack.h $(SDIR)/stack.h
	$(CXX) -c -o $@ $< $(CFLAGS)

$(ODIR)/sorting.o: sorting.cpp sorting.h $(ODIR)/heap.o
	$(CXX) -c -o $@ $< $(CFLAGS)

$(ODIR)/insertion_sort.o: sorting_algorithms/insertion_sort.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

$(ODIR)/selection_sort.o: sorting_algorithms/selection_sort.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

$(ODIR)/heapsort.o: sorting_algorithms/heapsort.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

$(ODIR)/merge_sort.o: sorting_algorithms/merge_sort.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

$(ODIR)/quicksort.o: sorting_algorithms/quicksort.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

insertion_sort: $(ODIR)/utils.o $(ODIR)/heap.o $(ODIR)/insertion_sort.o $(ODIR)/sorting.o
	$(CXX) -o $(BINDIR)/$@.out $^ $(CFLAGS)

selection_sort: $(ODIR)/utils.o $(ODIR)/heap.o $(ODIR)/selection_sort.o $(ODIR)/sorting.o
	$(CXX) -o $(BINDIR)/$@.out $^ $(CFLAGS)

heapsort: $(ODIR)/utils.o $(ODIR)/heap.o $(ODIR)/heapsort.o $(ODIR)/sorting.o
	$(CXX) -o $(BINDIR)/$@.out $^ $(CFLAGS)

merge_sort: $(ODIR)/utils.o $(ODIR)/heap.o $(ODIR)/merge_sort.o $(ODIR)/sorting.o
	$(CXX) -o $(BINDIR)/$@.out $^ $(CFLAGS)

quicksort: $(ODIR)/utils.o $(ODIR)/heap.o $(ODIR)/quicksort.o $(ODIR)/sorting.o
	$(CXX) -o $(BINDIR)/$@.out $^ $(CFLAGS)

sorting_algorithms: insertion_sort selection_sort heapsort merge_sort quicksort
