<?xml version="1.0"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:wix="http://schemas.microsoft.com/wix/2006/wi" xmlns="http://schemas.microsoft.com/wix/2006/wi" exclude-result-prefixes="xsl wix">

	<xsl:template match='wix:Directory[@Id="Swift"]/@Id'>
		<xsl:attribute name='Id'>INSTALLDIR</xsl:attribute>
	</xsl:template>

	<xsl:template match="@*|node()">
		<xsl:copy>
			<xsl:apply-templates select="@*|node()"/>
		</xsl:copy>
	</xsl:template>

	<xsl:template match="wix:Component">
		<xsl:copy>
			<xsl:apply-templates select="@*"/>
			<xsl:value-of select="concat(preceding-sibling::text(), '    ')" />
			<RemoveFile Id="remove_{@Id}" Name="{@Id}" On="install" />
			<xsl:apply-templates select="node()"/>
		</xsl:copy>
	</xsl:template>

</xsl:stylesheet>
