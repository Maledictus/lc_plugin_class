{% load kdev_filters %}
{% block license_header %}
/**********************************************************************

  {{ license|lines_prepend:" * " }}
 **********************************************************************/

{% endblock license_header %}

{% block includes %}
#include "{{ output_file_header }}"

{% endblock includes %}


{% block namespaces_open %}
{% for ns in namespaces %}
namespace {{ ns }}
{
{% endfor %}
{% endblock namespaces_open %}

{% block extra_declarations %}
{% endblock extra_declarations %}

{% block extra_definitions %}
{% endblock extra_definitions %}

{% block function_definitions %}
{% for method in functions %}
{% with method.arguments as arguments %}

{% if method.isConstructor %}
{{ name }}::{{ name }}
{% else %}
{{ method.returnType|default:"void" }} {{ name }}::{{ method.name }}({% include "arguments_types_names.txt" %}){% if method.isConst %} const{% endif %}
{% endif %}
{


}

{% endwith %}
{% endfor %}

{% endblock function_definitions %}

{% block namespaces_close %}
{% include "namespace_close_cpp.txt" %}
{% endblock namespaces_close %}