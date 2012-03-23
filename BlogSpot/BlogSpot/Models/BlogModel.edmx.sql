
-- --------------------------------------------------
-- Entity Designer DDL Script for SQL Server 2005, 2008, and Azure
-- --------------------------------------------------
-- Date Created: 03/23/2012 10:44:35
-- Generated from EDMX file: E:\PROGRAMMING CODE\BlogSpot\BlogSpot\Models\BlogModel.edmx
-- --------------------------------------------------

SET QUOTED_IDENTIFIER OFF;
GO
USE [BlogData];
GO
IF SCHEMA_ID(N'dbo') IS NULL EXECUTE(N'CREATE SCHEMA [dbo]');
GO

-- --------------------------------------------------
-- Dropping existing FOREIGN KEY constraints
-- --------------------------------------------------


-- --------------------------------------------------
-- Dropping existing tables
-- --------------------------------------------------


-- --------------------------------------------------
-- Creating all tables
-- --------------------------------------------------

-- Creating table 'Blogs'
CREATE TABLE [dbo].[Blogs] (
    [Id] int IDENTITY(1,1) NOT NULL,
    [Title] nvarchar(max)  NOT NULL,
    [BloggerName] nvarchar(max)  NOT NULL
);
GO

-- Creating table 'Comments'
CREATE TABLE [dbo].[Comments] (
    [Id] int IDENTITY(1,1) NOT NULL,
    [DateCreated] datetime  NOT NULL,
    [Content] nvarchar(max)  NOT NULL,
    [PostId] int  NOT NULL
);
GO

-- Creating table 'Posts'
CREATE TABLE [dbo].[Posts] (
    [Id] int IDENTITY(1,1) NOT NULL,
    [Title] nvarchar(max)  NOT NULL,
    [DateCreated] datetime  NOT NULL,
    [Content] nvarchar(max)  NULL,
    [BlogId] int  NOT NULL
);
GO

-- --------------------------------------------------
-- Creating all PRIMARY KEY constraints
-- --------------------------------------------------

-- Creating primary key on [Id] in table 'Blogs'
ALTER TABLE [dbo].[Blogs]
ADD CONSTRAINT [PK_Blogs]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- Creating primary key on [Id] in table 'Comments'
ALTER TABLE [dbo].[Comments]
ADD CONSTRAINT [PK_Comments]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- Creating primary key on [Id] in table 'Posts'
ALTER TABLE [dbo].[Posts]
ADD CONSTRAINT [PK_Posts]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- --------------------------------------------------
-- Creating all FOREIGN KEY constraints
-- --------------------------------------------------

-- Creating foreign key on [BlogId] in table 'Posts'
ALTER TABLE [dbo].[Posts]
ADD CONSTRAINT [FK_BlogPost]
    FOREIGN KEY ([BlogId])
    REFERENCES [dbo].[Blogs]
        ([Id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;

-- Creating non-clustered index for FOREIGN KEY 'FK_BlogPost'
CREATE INDEX [IX_FK_BlogPost]
ON [dbo].[Posts]
    ([BlogId]);
GO

-- Creating foreign key on [PostId] in table 'Comments'
ALTER TABLE [dbo].[Comments]
ADD CONSTRAINT [FK_PostComment]
    FOREIGN KEY ([PostId])
    REFERENCES [dbo].[Posts]
        ([Id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;

-- Creating non-clustered index for FOREIGN KEY 'FK_PostComment'
CREATE INDEX [IX_FK_PostComment]
ON [dbo].[Comments]
    ([PostId]);
GO

-- --------------------------------------------------
-- Script has ended
-- --------------------------------------------------