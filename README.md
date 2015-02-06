# CAS Intergration

## Introduction

### Openroad

[OpenRoad](http://openroad.vn/) is the Open collaboration platform, Openroad offers a set of services to help people share their experience with open technologies and support them to find, choose, re-use, develop, and implement shareable software and shared assets. Openroad is based on the Joinup platform, developed by the European Commissions via the Interoperability Solutions for Public Administrations (ISA) Programme. The platform is made available under the GNU GPL 2.0 license. Refer: [Joinup](https://joinup.ec.europa.eu/).

For more infos, please visit: [Openroad](https://github.com/Openroadvietnam/openroad).

### [CAS](https://github.com/Jasig/cas/) is the standard mechanism by which web applications should authenticate users.

CAS provides enterprise single sign-on service:

* An open and well-documented protocol
* An open-source Java server component
* A library of clients for Java, .Net, PHP, Perl, Apache, uPortal, and others
* Integrates with uPortal, BlueSocket, TikiWiki, Mule, Liferay, Moodle and others
* Community documentation and implementation support
* An extensive community of adopters


## Why do we need to intergrate CAS into Openroad?

Openroad have many intergrated software. We need to SSO gurantee for user that  one account use for every software.

Openroad use  [CAS server](https://github.com/Jasig/cas) and [CAS client](https://wiki.jasig.org/display/CASC/Home) to do that.
## Documentation

   * CAS Server Setup: 
     * https://github.com/Openroadvietnam/CAS-integration/wiki/C%C3%A0i-%C4%91%E1%BA%B7t-CAS-server-tr%C3%AAn-CentOS-6
     * https://wiki.jasig.org/display/CASUM/Best+Practice+-+Setting+Up+CAS+Locally+using+the+Maven+WAR+Overlay+Method
   * CAS Client: https://wiki.jasig.org/display/CASC/Home

## Support

  * IRC: #openroad on irc.freenode.net
  * Mailing list: http://lists.openroad.vn/mailman/listinfo/

## License

Openroad và integrated module keep author license and distribute with GNU GPL v2.0. For more info, please visit [LICENSE](LICENSE).
