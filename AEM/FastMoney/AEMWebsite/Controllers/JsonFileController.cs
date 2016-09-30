using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Text;
using System.Web.Http;
using System.Web;
using Newtonsoft.Json;
using AemClient;

namespace AEMWebsite.Controllers
{
    public class JsonFileController : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem.json"));
            List<Rootobject> n = new List<Rootobject>();
            Rootobject r = JsonConvert.DeserializeObject<Rootobject>(json);
            foreach (var item in r.newsList)
            {
                item.image = "http://mobilemarketingwatch.com/wp-content/uploads/2015/12/Can-Amobee-Cross-Channel-Video-Ads-Boost-Reach-of-TV-Campaigns-Company-Commissions-Nielsen-to-Find-Out-480x320.jpg";
                item.video = "https://r11---sn-q4f7snes.googlevideo.com/videoplayback?id=o-AGIU6Gum6AcygppDHIReDQde2ji5UZpmeRN6s78pUFRc&dur=192.200&source=youtube&sparams=clen,dur,ei,gir,id,initcwndbps,ip,ipbits,itag,keepalive,lmt,mime,mm,mn,ms,mv,nh,pl,requiressl,source,upn,expire&keepalive=yes&ip=38.84.37.2&requiressl=yes&lmt=1428044362972013&itag=135&ms=au&ei=NzDuV8u2MdOBugX9pomADQ&pl=23&mv=m&mt=1475227137&clen=15962225&signature=C69942309AEA93791BF17292CB611D9C7F43DB56.34E34A88F26045F259B4FA7B6D8A3F01B35EA088&key=yt6&mn=sn-q4f7snes&mm=31&gir=yes&ipbits=0&initcwndbps=911250&expire=1475249303&upn=HXzS6CiXn2E&mime=video/mp4&nh=IgpwZjAyLmRmdzA2Kg4zOC4xNDAuMTA1LjE5Mw&ratebypass=yes";
            }

            string str = JsonConvert.SerializeObject(r);
            return new HttpResponseMessage()
            {
                Content = new StringContent(str, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }
}

