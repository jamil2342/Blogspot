using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace FastMoneyClient
{
    public class myCleint
    {

        public myCleint()
        { 
        
        }


        public DataTable GetFastMoneyDataTable()
        {
            string result = "";
            HttpClient client = new HttpClient();
            HttpResponseMessage response = client.GetAsync("http://podcast.cnbc.com/mmpodcast/fastmoney.xml").Result;
            string str = response.Content.ReadAsStringAsync().Result;

            XmlDocument xmlResult1 = new XmlDocument();
            xmlResult1.LoadXml(str);

            var xmlTag = xmlResult1.GetElementsByTagName("item");

            DataTable dt = ConvertXmlNodeListToDataTable(xmlTag);


            int desiredSize = 2;

            while (dt.Columns.Count > desiredSize)
            {
                dt.Columns.RemoveAt(desiredSize);
            }
            return dt;

        }

        public DataTable ConvertXmlNodeListToDataTable(XmlNodeList xmlTag)
        {
            DataTable dt = new DataTable("FastMoney");
            int TempColumn = 0;

            foreach (XmlNode node in xmlTag.Item(0).ChildNodes)
            {
                TempColumn++;
                DataColumn dc = new DataColumn(node.Name, System.Type.GetType("System.String"));
                if (dt.Columns.Contains(node.Name))
                {
                    dt.Columns.Add(dc.ColumnName = dc.ColumnName + TempColumn.ToString());
                }
                else
                {
                    dt.Columns.Add(dc);
                }
            }

            int ColumnsCount = dt.Columns.Count;
            for (int i = 0; i < xmlTag.Count; i++)
            {
                DataRow dr = dt.NewRow();
                for (int j = 0; j < ColumnsCount; j++)
                {
                    dr[j] = xmlTag.Item(i).ChildNodes[j].InnerText;
                }
                dt.Rows.Add(dr);
            }
            return dt;
        }
       
       
    }
}
