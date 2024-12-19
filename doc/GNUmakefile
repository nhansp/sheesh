DOC_DIR = .
SITE_DIR = ${DOC_DIR}/public_html

SUFFIX +=
RST2MAN = rst2man${SUFFIX}
RST2XML = rst2xml${SUFFIX}
RST2HTML = rst2html${SUFFIX}

OUTPUTS = sheesh/man.1 sheesh.h sheesh/rpm-spec sheesh/index.html care.h care/index.html
all: $(OUTPUTS) # dist

dist: $(OUTPUTS)
	@mkdir -p ${SITE_DIR}/care
	@cp care/index.html ${SITE_DIR}/care/index.html
	@cp care/stylesheets/website.css ${SITE_DIR}/care/care.css
	@cp stylesheets/website.css ${SITE_DIR}/care
	@cp sheesh/index.html ${SITE_DIR}/index.html
	@cp sheesh/stylesheets/website.css ${SITE_DIR}/sheesh.css
	@cp stylesheets/website.css ${SITE_DIR}/
	@cp ${DOC_DIR}/../COPYING ${SITE_DIR}/
	@cp ${DOC_DIR}/../README.rst ${SITE_DIR}/
	@cp ${DOC_DIR}/../HACKING.rst ${SITE_DIR}/

%/man.1: %/manual.rst
	$(RST2MAN) $< $@

%.xml: %.rst
	$(RST2XML) --no-doctype $< $@

%.html: %.rst
	$(RST2HTML) $< $@

# Workaround to avoid unescaped C character.
%/manual-quoted.rst: %/manual.rst
	sed 's/"/\\\\"/g' $^ > $@

%.h: %/stylesheets/cli.xsl %/manual-quoted.xml
	xsltproc --output $@ $^

%/rpm-spec:  %/stylesheets/rpm-spec.xsl %/manual.xml
	xsltproc --output $@ $^
	echo "* $(shell date +'%a %b %d %Y') PRoot Team <sheesh_me@googlegroups.com>" >> $@

%/index.html: stylesheets/website.xsl %/stylesheets/website.xsl %/manual.xml
	xsltproc --output $@ $*/stylesheets/website.xsl $*/manual.xml

clean:
	rm -f *.xml $(OUTPUTS) *-quoted.* public_html
