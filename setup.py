from setuptools import setup
from Cython.Build import cythonize

setup(
    name='Cube',
    ext_modules=cythonize("Cube.pyx"),
    zip_safe=False,
)

#python setup.py build_ext --inplace