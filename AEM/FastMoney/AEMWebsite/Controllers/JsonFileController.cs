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
    public class JsonFile1Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem1.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }
    public class JsonFile2Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem1.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }

    public class JsonFile3Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem1.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }

    public class JsonFile4Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem1.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }

    public class JsonFile5Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem1.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }

    public class JsonFile6Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem1.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }

    public class JsonFile7Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem1.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }

    public class JsonFile8Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem1.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }

    public class JsonFile9Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem1.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }

    public class JsonFile10Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem1.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }

    public class JsonFile11Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem1.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }

    public class JsonFile12Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem1.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }

    public class JsonFile13Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem1.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }

    public class JsonFile14Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem1.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }

    public class JsonFile15Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem1.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }


}

