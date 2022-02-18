PORTNAME=	plex-ttf
DISTVERSION=	6.0.0
CATEGORIES=	x11-fonts
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	IBM's signature typeface

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/TrueType/IBM-Plex-Mono/license.txt

USES=		fonts zip
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	IBM
GH_PROJECT=	plex
GH_TAGNAME=	v${DISTVERSION}
GH_ASSET=	TrueType${EXTRACT_SUFX}

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${FIND} ${WRKSRC} -name *.ttf -type f \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${FONTSDIR} \;

.include <bsd.port.mk>
