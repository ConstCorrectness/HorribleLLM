import os
import sys
sys.path.insert(0, os.path.abspath('../horriblellm'))

project = 'HorribleLLM'
author = 'Horrible Program'
release = '0.1.0'

extensions = [
    'myst_parser',
    'sphinx.ext.autodoc',
    'sphinx.ext.napoleon',
    'breathe'
]

html_theme = 'sphinx_rtd_theme'
breathe_projects = {"HorribleLLM": "../build/doxygen/xml"}
breathe_default_project = "HorribleLLM"