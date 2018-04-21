
#include<osg/Node>
#include<osg/PagedLOD>
#include<osgDB/ReadFile>

class SenceTreeVisitor :public osg::NodeVisitor
{
public:
	SenceTreeVisitor() :osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN),_indent(0)
	{
	}
	//osg::Node
	virtual void apply(osg::Node& node)
	{
		for (int i = 0; i < _indent; ++i)
		{
			std::cout << "  ";
			
		}
		std::cout << "[" << _indent + 1 << "]" << node.libraryName() << "::" << node.className() << std::endl;
		_indent++;
		traverse(node);
		_indent--;
	}
	//osg::PageLOD
	virtual void apply(osg::PagedLOD& node)
	{
		for (int i = 0; i < _indent; ++i)
		{
			std::cout << "  ";

		}
		std::cout << "[" << _indent + 1 << "]" << node.libraryName() << "::" << node.className() << std::endl;
		_indent++;
		traverse(node);
		_indent--;
	}
	//osg::Geode
	void apply(osg::Geode& geode)
	{
		for (int i = 0; i < _indent; ++i)
		{
			std::cout << "  ";

		}
		std::cout << "[" << _indent + 1 << "]" << geode.libraryName() << "::" << geode.className() <<  std::endl;
		for (int  n = 0; n < geode.getNumDrawables(); ++n)
		{
			osg::Drawable* drawable = geode.getDrawable(n);
			if (!drawable) continue;

			for (int i = 0; i <= _indent; ++i)
			{
				std::cout << "  ";
			}
			std::cout << drawable->libraryName() << "::" << drawable->className() << std::endl;
		}
		// �˴���ΪҶ�ڵ㣬Ӧ�������ӽڵ㣬�ʲ����������ӽڵ����
	}
protected:
	int _indent;
};
int main()
{
	mark:
	std::string fileName;
	std::cout << "Path of Model:";
	std::cin >> fileName;
	SenceTreeVisitor textureTV;
	osgDB::readNodeFile(fileName)->accept(textureTV);
	
	goto mark;
	return 0;
}