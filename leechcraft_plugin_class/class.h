{% load kdev_filters %}
{% block license_header %}
/**********************************************************************

  {{ license|lines_prepend:" * " }}
 **********************************************************************/

{% endblock license_header %}

{% block pragma %}
#pragma once

{% endblock pragma %}

{% block includes %}
{% for included_file in included_files %}
#include {{ included_file }}
{% endfor %}

{% endblock includes %}

{% block namespaces_open %}
{% for ns in namespaces %}
namespace {{ ns }}
{
{% endfor %}
{% endblock namespaces_open %}

{% block forward_declarations %}
{% endblock forward_declarations %}

{% block class_declaration_open %}
class {{ name }}{% if base_classes %} :{% for base in base_classes %} {{ base.inheritanceMode }} {{ base.baseType }}
{% if not forloop.last %},{% endif %}{% endfor %}{% endif %}
{
{% endblock class_declaration_open %}
	Q_OBJECT
{% block interfaces %}
	Q_INTERFACES ({% for base in base_classes %}{% with base.baseType|make_list|first as first_symbol %}{% ifequal first_symbol 'I' %}{{ base.baseType }} {% endifequal %}{% endwith %}{% endfor %})

{% endblock interfaces %}
{% block class_body %}

{% for member in private_members %}
	{{ member.type }} {{ member.name }};
{% endfor %}

{% if public_members or public_functions %}

public:
{% endif %}
{% for member in public_members reversed %}
	{{ member.type }} {{ member.name }};
{% endfor %}

{% for method in public_functions %}
	{% include "method_declaration_cpp.txt" %}
{% endfor %}

{% if protected_members or protected_functions %}
protected:
{% endif %}
{% for member in protected_members %}
	{{ member.type }} {{ member.name }};
{% endfor %}

{% for method in protected_functions %}
	{% include "method_declaration_cpp.txt" %}
{% endfor %}

{% if private_functions %}
private:
{% endif %}
{% for method in private_functions %}
	{% include "method_declaration_cpp.txt" %}
{% endfor %}

{% endblock class_body %}

{% block class_bottom %}
{% endblock %}

{% block class_declaration_close %}
};
{% endblock %}

{% block outside_class %}
{% endblock %}

{% block namespaces_close %}
{% include "namespace_close_cpp.txt" %}
{% endblock namespaces_close %}

{% block outside_namespace %}
{% endblock %}
