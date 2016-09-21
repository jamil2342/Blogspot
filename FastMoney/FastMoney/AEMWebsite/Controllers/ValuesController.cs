using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using Newtonsoft.Json;
using FastMoneyClient;

namespace AEMWebsite.Controllers
{
    public class ValuesController : ApiController
    {
        // GET api/values
        public IEnumerable<string> Get()
        {
            return new string[] { "value1", "value2" };
        }
        public string GetAem()
        {
            List<Newslist> l = new List<Newslist>();

            Newslist n = new Newslist();
            Newslist n1 = new Newslist();
            Newslist n2 = new Newslist();
            n.headline = "";
            n._abstract = "";
            n.image = @"/content/dam/ebase/Nachrichten/2016/07/ONE1607_LAAA_160427_Barthelmeh-194_Kopfbild.jpg";


            n1.headline = "";
            n1._abstract = "";
            n1.image = "/content/dam/ebase/Nachrichten/2016/07/160629_DiscoverLH-2.jpg/jcr:content/renditions/cq5dam.web.1280.1280.jpeg.image_file.881.494.0%2c39%2c1280%2c757.file";

            n2.headline = "";
            n2._abstract = "";
            n2.image = "";
           
            return JsonConvert.SerializeObject(l);
        }

        // GET api/values/5
        public string Get(int id)
        {
            return "value";
        }

        // POST api/values
        public void Post([FromBody]string value)
        {
        }

        // PUT api/values/5
        public void Put(int id, [FromBody]string value)
        {
        }

        // DELETE api/values/5
        public void Delete(int id)
        {
        }
    }
}