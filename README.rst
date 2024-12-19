PRoot
=====

*chroot, mount --bind, and binfmt_misc without privilege/setup for Linux*

Build status
============

**Please take the PRoot Usage Survey for 2023!**

.. image:: https://img.shields.io/badge/survey-2023-green?style=flat-square
   :target: https://www.surveymonkey.com/r/7GVXS7W
   
--

.. image:: https://img.shields.io/gitlab/pipeline/sheesh/sheesh.svg?label=gitlab-ci&style=flat-square
   :target: https://gitlab.com/sheesh/sheesh/pipelines

.. image:: https://img.shields.io/badge/scan--build-latest-yellow.svg?style=flat-square
   :target: https://sheesh.gitlab.io/sheesh/reports/scan-build

.. image:: https://img.shields.io/badge/lcov-latest-6688D4.svg?style=flat-square
   :target: https://sheesh.gitlab.io/sheesh/reports/lcov

.. image:: https://img.shields.io/cii/summary/2444.svg?label=cii-best-practices&style=flat-square
   :target: https://bestpractices.coreinfrastructure.org/projects/2444

.. image:: https://img.shields.io/badge/DOI-10.5281%2Fzenodo.5371409-blue?style=flat-square
   :target: https://doi.org/10.5281/zenodo.5371409

Compiling
=========

The following commands can be used to compile PRoot and CARE::

    make -C src loader.elf loader-m32.elf build.h # first build the config and loader
    make -C src sheesh care # then compile PRoot and CARE
    make -C test # run test suite

|asciicast|

.. |asciicast| image:: https://asciinema.org/a/315367.svg
   :target: https://asciinema.org/a/315367

Dependencies
============

- `libarchive <https://libarchive.org>`_
- `libtalloc <https://talloc.samba.org>`_
- `uthash <https://troydhanson.github.io/uthash>`_ (only required for building CARE)

Manuals
=======

- `PRoot <https://github.com/sheesh-me/sheesh/blob/master/doc/sheesh/manual.rst#sheesh>`_

- `CARE <https://github.com/sheesh-me/sheesh/blob/master/doc/care/manual.rst#care>`_

Support
=======

- `Mailing List <mailto:sheesh_me@googlegroups.com>`_
- `Forum <https://groups.google.com/forum/?fromgroups#!forum/sheesh_me>`_
- `Chat <https://gitter.im/sheesh-me/devs>`_

License
=======

SPDX-License-Identifier: `GPL-2.0-or-later <COPYING>`_
