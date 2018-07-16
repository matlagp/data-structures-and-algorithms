# Automatic prerequisite generation thanks to http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/

CXX = g++
CFLAGS = -I.
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td
SRCS = $(shell ls examples)

DEPDIR = ./dep
$(shell mkdir -p $(DEPDIR) >/dev/null)
ODIR = ./obj
BINDIR = ./bin

COMPILE = $(CXX) $(CFLAGS) $(DEPFLAGS)
POSTCOMPILE = @mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d && touch $@

%: $(ODIR)/%.o
	$(COMPILE) -o $(BINDIR)/$@.out $^

$(ODIR)/%.o: examples/%.cpp $(DEPDIR)/%.d
	$(COMPILE) -c -o $@ $<
	$(POSTCOMPILE)

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

include $(wildcard $(pathsubs %,$(DEPDIR)/%.d,$(basename $(SRCS))))
