CXX=g++
SDIR=./structs
CFLAGS=-I$(SDIR)

ODIR=./obj

BINDIR=./bin

$(ODIR)/array.o: $(SDIR)/array.cpp $(SDIR)/array.h
	$(CXX) -c -o $@ $< $(CFLAGS)

$(ODIR)/heap.o: $(SDIR)/heap.cpp $(SDIR)/heap.h
	$(CXX) -c -o $@ $< $(CFLAGS)

$(ODIR)/linked_list.o: $(SDIR)/linked_list.cpp $(SDIR)/linked_list.h
	$(CXX) -c -o $@ $< $(CFLAGS)

$(ODIR)/heapsort.o: sorting_algorithms/heapsort.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

heapsort: $(ODIR)/heapsort.o $(ODIR)/heap.o $(ODIR)/array.o
	$(CXX) -o $(BINDIR)/$@.out $^ $(CFLAGS)
