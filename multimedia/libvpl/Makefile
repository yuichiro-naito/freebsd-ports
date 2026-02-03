PORTNAME=	libvpl
DISTVERSIONPREFIX=	v
DISTVERSION=	2.16.0
CATEGORIES=	multimedia

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	oneAPI Video Processing Library dispatcher, tools, and examples
WWW=		https://software.intel.com/content/www/us/en/develop/tools/oneapi/components/onevpl.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	only Intel GPUs on x86 are supported

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libva.so:multimedia/libva \
		libwayland-client.so:graphics/wayland

USES=		cmake:testing compiler:c++14-lang localbase:ldflags pkgconfig \
		xorg
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	intel
USE_LDCONFIG=	yes
USE_XORG=	x11 xcb

CMAKE_TESTING_ON=	BUILD_TESTS
CONFLICTS=	multimedia/onevpl
DATADIR=	${PREFIX}/share/vpl

post-patch:
	@${REINPLACE_CMD} -e '/pkgconfig/s,FULL_LIBDIR},PREFIX}/libdata,' \
		${WRKSRC}/libvpl/CMakeLists.txt
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},' \
		${WRKSRC}/libvpl/src/mfx_dispatcher_vpl_loader.cpp

post-install:
	@${FIND} ${STAGEDIR} -name \*.orig -delete

.include <bsd.port.mk>
