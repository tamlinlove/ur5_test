from setuptools import find_packages
from setuptools import setup

setup(
    name='ur5_test',
    version='0.0.0',
    packages=find_packages(
        include=('ur5_test', 'ur5_test.*')),
)
