﻿//------------------------------------------------------------------------------
// <auto-generated>
//    This code was generated from a template.
//
//    Manual changes to this file may cause unexpected behavior in your application.
//    Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using System;
using System.Data.Objects;
using System.Data.Objects.DataClasses;
using System.Data.EntityClient;
using System.ComponentModel;
using System.Xml.Serialization;
using System.Runtime.Serialization;

[assembly: EdmSchemaAttribute()]

namespace BlogSpot.Models
{
    #region Contexts
    
    /// <summary>
    /// No Metadata Documentation available.
    /// </summary>
    public partial class BlogModelContainer : ObjectContext
    {
        #region Constructors
    
        /// <summary>
        /// Initializes a new BlogModelContainer object using the connection string found in the 'BlogModelContainer' section of the application configuration file.
        /// </summary>
        public BlogModelContainer() : base("name=BlogModelContainer", "BlogModelContainer")
        {
            this.ContextOptions.LazyLoadingEnabled = true;
            OnContextCreated();
        }
    
        /// <summary>
        /// Initialize a new BlogModelContainer object.
        /// </summary>
        public BlogModelContainer(string connectionString) : base(connectionString, "BlogModelContainer")
        {
            this.ContextOptions.LazyLoadingEnabled = true;
            OnContextCreated();
        }
    
        /// <summary>
        /// Initialize a new BlogModelContainer object.
        /// </summary>
        public BlogModelContainer(EntityConnection connection) : base(connection, "BlogModelContainer")
        {
            this.ContextOptions.LazyLoadingEnabled = true;
            OnContextCreated();
        }
    
        #endregion
    
        #region Partial Methods
    
        partial void OnContextCreated();
    
        #endregion
    
        #region ObjectSet Properties
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        public ObjectSet<Entity1> Entity1
        {
            get
            {
                if ((_Entity1 == null))
                {
                    _Entity1 = base.CreateObjectSet<Entity1>("Entity1");
                }
                return _Entity1;
            }
        }
        private ObjectSet<Entity1> _Entity1;
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        public ObjectSet<Entity2> Entity2
        {
            get
            {
                if ((_Entity2 == null))
                {
                    _Entity2 = base.CreateObjectSet<Entity2>("Entity2");
                }
                return _Entity2;
            }
        }
        private ObjectSet<Entity2> _Entity2;
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        public ObjectSet<Entity3> Entity3
        {
            get
            {
                if ((_Entity3 == null))
                {
                    _Entity3 = base.CreateObjectSet<Entity3>("Entity3");
                }
                return _Entity3;
            }
        }
        private ObjectSet<Entity3> _Entity3;

        #endregion
        #region AddTo Methods
    
        /// <summary>
        /// Deprecated Method for adding a new object to the Entity1 EntitySet. Consider using the .Add method of the associated ObjectSet&lt;T&gt; property instead.
        /// </summary>
        public void AddToEntity1(Entity1 entity1)
        {
            base.AddObject("Entity1", entity1);
        }
    
        /// <summary>
        /// Deprecated Method for adding a new object to the Entity2 EntitySet. Consider using the .Add method of the associated ObjectSet&lt;T&gt; property instead.
        /// </summary>
        public void AddToEntity2(Entity2 entity2)
        {
            base.AddObject("Entity2", entity2);
        }
    
        /// <summary>
        /// Deprecated Method for adding a new object to the Entity3 EntitySet. Consider using the .Add method of the associated ObjectSet&lt;T&gt; property instead.
        /// </summary>
        public void AddToEntity3(Entity3 entity3)
        {
            base.AddObject("Entity3", entity3);
        }

        #endregion
    }
    

    #endregion
    
    #region Entities
    
    /// <summary>
    /// No Metadata Documentation available.
    /// </summary>
    [EdmEntityTypeAttribute(NamespaceName="BlogModel", Name="Entity1")]
    [Serializable()]
    [DataContractAttribute(IsReference=true)]
    public partial class Entity1 : EntityObject
    {
        #region Factory Method
    
        /// <summary>
        /// Create a new Entity1 object.
        /// </summary>
        /// <param name="id">Initial value of the Id property.</param>
        public static Entity1 CreateEntity1(global::System.Int32 id)
        {
            Entity1 entity1 = new Entity1();
            entity1.Id = id;
            return entity1;
        }

        #endregion
        #region Primitive Properties
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=true, IsNullable=false)]
        [DataMemberAttribute()]
        public global::System.Int32 Id
        {
            get
            {
                return _Id;
            }
            set
            {
                if (_Id != value)
                {
                    OnIdChanging(value);
                    ReportPropertyChanging("Id");
                    _Id = StructuralObject.SetValidValue(value);
                    ReportPropertyChanged("Id");
                    OnIdChanged();
                }
            }
        }
        private global::System.Int32 _Id;
        partial void OnIdChanging(global::System.Int32 value);
        partial void OnIdChanged();

        #endregion
    
    }
    
    /// <summary>
    /// No Metadata Documentation available.
    /// </summary>
    [EdmEntityTypeAttribute(NamespaceName="BlogModel", Name="Entity2")]
    [Serializable()]
    [DataContractAttribute(IsReference=true)]
    public partial class Entity2 : EntityObject
    {
        #region Factory Method
    
        /// <summary>
        /// Create a new Entity2 object.
        /// </summary>
        /// <param name="id">Initial value of the Id property.</param>
        public static Entity2 CreateEntity2(global::System.Int32 id)
        {
            Entity2 entity2 = new Entity2();
            entity2.Id = id;
            return entity2;
        }

        #endregion
        #region Primitive Properties
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=true, IsNullable=false)]
        [DataMemberAttribute()]
        public global::System.Int32 Id
        {
            get
            {
                return _Id;
            }
            set
            {
                if (_Id != value)
                {
                    OnIdChanging(value);
                    ReportPropertyChanging("Id");
                    _Id = StructuralObject.SetValidValue(value);
                    ReportPropertyChanged("Id");
                    OnIdChanged();
                }
            }
        }
        private global::System.Int32 _Id;
        partial void OnIdChanging(global::System.Int32 value);
        partial void OnIdChanged();

        #endregion
    
    }
    
    /// <summary>
    /// No Metadata Documentation available.
    /// </summary>
    [EdmEntityTypeAttribute(NamespaceName="BlogModel", Name="Entity3")]
    [Serializable()]
    [DataContractAttribute(IsReference=true)]
    public partial class Entity3 : EntityObject
    {
        #region Factory Method
    
        /// <summary>
        /// Create a new Entity3 object.
        /// </summary>
        /// <param name="id">Initial value of the Id property.</param>
        public static Entity3 CreateEntity3(global::System.Int32 id)
        {
            Entity3 entity3 = new Entity3();
            entity3.Id = id;
            return entity3;
        }

        #endregion
        #region Primitive Properties
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=true, IsNullable=false)]
        [DataMemberAttribute()]
        public global::System.Int32 Id
        {
            get
            {
                return _Id;
            }
            set
            {
                if (_Id != value)
                {
                    OnIdChanging(value);
                    ReportPropertyChanging("Id");
                    _Id = StructuralObject.SetValidValue(value);
                    ReportPropertyChanged("Id");
                    OnIdChanged();
                }
            }
        }
        private global::System.Int32 _Id;
        partial void OnIdChanging(global::System.Int32 value);
        partial void OnIdChanged();

        #endregion
    
    }

    #endregion
    
}
