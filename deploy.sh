#! /bin/sh

home_app=~/app

if test -d /llj/app ; then
   home_app=/llj/app
fi

home_slash=${home_app}/slash

./configure --prefix=${home_slash}

if test -d ${home_slash}; then
    rm -rf ${home_slash}
fi

make install

make distclean
