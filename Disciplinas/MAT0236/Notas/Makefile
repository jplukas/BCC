DATA_DIR:= .pandoc
DEFAULTS_FILE:= defaults.yaml
DIST_DIR:= dist
INPUT_FILES:= source/*.md
FLAGS:= --data-dir=$(DATA_DIR) $\
	--defaults=$(DEFAULTS_FILE) $\
	--output=$(DIST_DIR)/index.html

DIR_WATCH:= source

CLEAN:= rm -f $(DIST_DIR)/*
COMPILE:= pandoc $(FLAGS) $(INPUT_FILES)
COMPILE_DELAY:=500

$(DIST_DIR)/index.html: $(INPUT_FILES)
	$(COMPILE)

serve: 
	@jp-live-server $(DIR_WATCH) $(DIST_DIR) '$(COMPILE) $(COMPILE_DELAY)'

test:
	@echo $(COMPILE)

.PHONY:clean

clean:
	$(CLEAN)