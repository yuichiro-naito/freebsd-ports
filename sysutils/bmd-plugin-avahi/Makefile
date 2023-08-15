PORTNAME=	bmd-plugin-avahi
DISTVERSION=	1.0
CATEGORIES=	sysutils

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Bhyve Management Daemon
WWW=		https://github.com/yuichiro-naito/bmd-plugin-avahi

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bmd>0:sysutils/bmd
RUN_DEPENDS=	bmd>0:sysutils/bmd \
		avahi-app>0:net/avahi-app

USE_GITHUB=	yes
GH_ACCOUNT=	yuichiro-naito

pre-install:
	mkdir -p ${STAGEDIR}/${LOCALBASE}/libexec/bmd

.include <bsd.port.mk>
