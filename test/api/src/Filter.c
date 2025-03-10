#include <api.h>

void Filter_filter_1_term() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{TagA}}
    });

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, TagA);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].inout, EcsInOutDefault);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, TagA);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_component() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ ecs_id(Position) }}
    });

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, ecs_id(Position));
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].inout, EcsInOutDefault);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, ecs_id(Position));
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_2_terms() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{TagA}, {TagB}}
    });

    test_int(f.term_count, 2);
    test_int(f.field_count, 2);
    test_assert(f.terms != NULL);

    test_int(f.terms[0].id, TagA);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, TagA);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);

    test_int(f.terms[1].id, TagB);
    test_int(f.terms[1].oper, EcsAnd);
    test_int(f.terms[1].field_index, 1);
    test_int(f.terms[1].first.id, TagB);
    test_int(f.terms[1].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[1].src.id, EcsThis);
    test_int(f.terms[1].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[1].src.trav, EcsIsA);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_3_terms() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{TagA}, {TagB}, {TagC}}
    });

    test_int(f.term_count, 3);
    test_int(f.field_count, 3);
    test_assert(f.terms != NULL);

    test_int(f.terms[0].id, TagA);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, TagA);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);

    test_int(f.terms[1].id, TagB);
    test_int(f.terms[1].oper, EcsAnd);
    test_int(f.terms[1].field_index, 1);
    test_int(f.terms[1].first.id, TagB);
    test_int(f.terms[1].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[1].src.id, EcsThis);
    test_int(f.terms[1].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[1].src.trav, EcsIsA);

    test_int(f.terms[2].id, TagC);
    test_int(f.terms[2].oper, EcsAnd);
    test_int(f.terms[2].field_index, 2);
    test_int(f.terms[2].first.id, TagC);
    test_int(f.terms[2].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[2].src.id, EcsThis);
    test_int(f.terms[2].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[2].src.trav, EcsIsA);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_3_terms_w_or() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{TagA}, {TagB, .oper = EcsOr}, {TagC }}
    });

    test_int(f.term_count, 3);
    test_int(f.field_count, 2);
    test_assert(f.terms != NULL);

    test_int(f.terms[0].id, TagA);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, TagA);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);

    test_int(f.terms[1].id, TagB);
    test_int(f.terms[1].oper, EcsOr);
    test_int(f.terms[1].field_index, 1);
    test_int(f.terms[1].first.id, TagB);
    test_int(f.terms[1].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[1].src.id, EcsThis);
    test_int(f.terms[1].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[1].src.trav, EcsIsA);

    test_int(f.terms[2].id, TagC);
    test_int(f.terms[2].oper, EcsAnd);
    test_int(f.terms[2].field_index, 1);
    test_int(f.terms[2].first.id, TagC);
    test_int(f.terms[2].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[2].src.id, EcsThis);
    test_int(f.terms[2].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[2].src.trav, EcsIsA);
    
    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_4_terms_w_or_at_1() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, TagD);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{TagA}, {TagB, .oper = EcsOr}, {TagC}, {TagD}}
    });

    test_int(f.term_count, 4);
    test_int(f.field_count, 3);
    test_assert(f.terms != NULL);

    test_int(f.terms[0].id, TagA);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, TagA);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);

    test_int(f.terms[1].id, TagB);
    test_int(f.terms[1].oper, EcsOr);
    test_int(f.terms[1].field_index, 1);
    test_int(f.terms[1].first.id, TagB);
    test_int(f.terms[1].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[1].src.id, EcsThis);
    test_int(f.terms[1].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[1].src.trav, EcsIsA);

    test_int(f.terms[2].id, TagC);
    test_int(f.terms[2].oper, EcsAnd);
    test_int(f.terms[2].field_index, 1);
    test_int(f.terms[2].first.id, TagC);
    test_int(f.terms[2].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[2].src.id, EcsThis);
    test_int(f.terms[2].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[2].src.trav, EcsIsA);

    test_int(f.terms[3].id, TagD);
    test_int(f.terms[3].oper, EcsAnd);
    test_int(f.terms[3].field_index, 2);
    test_int(f.terms[3].first.id, TagD);
    test_int(f.terms[3].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[3].src.id, EcsThis);
    test_int(f.terms[3].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[3].src.trav, EcsIsA);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_wildcard() {
    ecs_world_t *world = ecs_mini();

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ EcsWildcard }}
    });

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, EcsWildcard);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, EcsWildcard);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsVariable);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);
    test_int(f.terms[0].second.id, 0);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_any() {
    ecs_world_t *world = ecs_mini();

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ EcsAny }}
    }));

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, EcsAny);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, EcsAny);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsVariable);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);
    test_int(f.terms[0].second.id, 0);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_same_subj_obj() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Foo);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_t *r = ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .first.id = Rel, .src.name = "Foo", .second.name = "Foo" }}
    });
    test_assert(r != NULL);

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, ecs_pair(Rel, Foo));
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Rel);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, Foo);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsEntity);
    test_int(f.terms[0].src.trav, EcsIsA);
    test_int(f.terms[0].second.id, Foo);
    test_int(f.terms[0].second.flags, EcsSelf|EcsIsEntity);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_acyclic_same_subj_obj() {
    ecs_log_set_level(-4);

    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Rel, Traversable);
    ECS_TAG(world, Foo);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL == ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .first.id = Rel, .src.name = "Foo", .second.name = "Foo" }}
    }));

    ecs_fini(world);
}

void Filter_filter_1_term_acyclic_reflexive_same_subj_obj() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Rel, Traversable, Reflexive);
    ECS_TAG(world, Foo);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_t *r = ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .first.id = Rel, .src.name = "Foo", .second.name = "Foo" }}
    });
    test_assert(r != NULL);

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, ecs_pair(Rel, Foo));
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Rel);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, Foo);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsEntity);
    test_int(f.terms[0].src.trav, EcsIsA);
    test_int(f.terms[0].second.id, Foo);
    test_int(f.terms[0].second.flags, EcsSelf|EcsIsEntity);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_same_subj_obj_var() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_t *r = ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .first.id = Rel, 
            .src = { .name = "X", .flags = EcsIsVariable },
            .second = { .name = "X", .flags = EcsIsVariable }
        }}
    });
    test_assert(r != NULL);

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, ecs_pair(Rel, EcsWildcard));
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Rel);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_str(f.terms[0].src.name, "X");
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);
    test_str(f.terms[0].second.name, "X");
    test_int(f.terms[0].second.flags, EcsSelf|EcsIsVariable);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_acyclic_same_subj_obj_var() {
    ecs_log_set_level(-4);

    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Rel, Traversable);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL == ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .first.id = Rel, 
            .src = { .name = "X", .flags = EcsIsVariable },
            .second = { .name = "X", .flags = EcsIsVariable }
        }}
    }));

    ecs_fini(world);
}

void Filter_filter_1_term_acyclic_reflexive_same_subj_obj_var() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Rel, Traversable, Reflexive);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_t *r = ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .first.id = Rel, 
            .src = { .name = "X", .flags = EcsIsVariable },
            .second = { .name = "X", .flags = EcsIsVariable }
        }}
    });
    test_assert(r != NULL);

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, ecs_pair(Rel, EcsWildcard));
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Rel);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_str(f.terms[0].src.name, "X");
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);
    test_str(f.terms[0].second.name, "X");
    test_int(f.terms[0].second.flags, EcsSelf|EcsIsVariable);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_non_acyclic_superset() {
    ecs_log_set_level(-4);

    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);
    ECS_TAG(world, Rel);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL == ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .id = Tag, 
            .src.flags = EcsUp,
            .src.trav = Rel
        }}
    })); /* cyclic superset is invalid  */

    ecs_fini(world);
}

void Filter_filter_1_term_dont_inherit_default_set() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Tag, DontInherit);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_t *r = ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .id = Tag }}
    });
    test_assert(r != NULL);

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, Tag);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Tag);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsIsVariable);
    test_int(f.terms[0].src.trav, 0);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_dont_inherit_pair_default_set() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Rel, DontInherit);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_t *r = ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .id = ecs_pair(Rel, EcsWildcard) }}
    });
    test_assert(r != NULL);

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, ecs_pair(Rel, EcsWildcard));
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Rel);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsIsVariable);
    test_int(f.terms[0].src.trav, 0);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_cascade_implicit_isa() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_t *r = ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .id = Tag, .src.flags = EcsCascade }}
    });
    test_assert(r != NULL);

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, Tag);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Tag);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsUp|EcsCascade|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_cascade_isa() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_t *r = ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .id = Tag, 
            .src.trav = EcsIsA, .src.flags = EcsCascade
        }}
    });
    test_assert(r != NULL);

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, Tag);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Tag);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsUp|EcsCascade|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_cascade_childof() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_t *r = ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .id = Tag, 
            .src.trav = EcsChildOf, .src.flags = EcsCascade
        }}
    });
    test_assert(r != NULL);

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, Tag);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Tag);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsUp|EcsCascade|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsChildOf);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_cascade_down() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_t *r = ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .id = Tag, 
            .src.trav = EcsChildOf, .src.flags = EcsCascade
        }}
    });
    test_assert(r != NULL);

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, Tag);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Tag);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsUp|EcsCascade|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsChildOf);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_optional_only() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_t *r = ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .id = Tag, 
            .oper = EcsOptional
        }}
    });
    test_assert(r != NULL);

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, Tag);
    test_int(f.terms[0].oper, EcsOptional);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Tag);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_transitive_pair() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Rel, Transitive);
    ECS_TAG(world, Tgt);
    
    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_t *r = ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .id = ecs_pair(Rel, Tgt)
        }}
    });
    test_assert(r != NULL);

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, ecs_pair(Rel, Tgt));
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Rel);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);
    test_int(f.terms[0].second.id, Tgt);
    test_int(f.terms[0].second.flags, EcsSelf|EcsUp|EcsTraverseAll|EcsIsEntity);
    test_int(f.terms[0].second.trav, Rel);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_transitive_pair_explicit_self_tgt() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Rel, Transitive);
    ECS_TAG(world, Tgt);
    
    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_t *r = ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .id = ecs_pair(Rel, Tgt),
            .second.flags = EcsSelf
        }}
    });
    test_assert(r != NULL);

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, ecs_pair(Rel, Tgt));
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Rel);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);
    test_int(f.terms[0].second.id, Tgt);
    test_int(f.terms[0].second.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].second.trav, 0);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_variable_as_pred_only() {
    ecs_log_set_level(-4);

    ecs_world_t *world = ecs_mini();

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL == ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .id = EcsVariable }}
    }));

    ecs_fini(world);
}

void Filter_filter_1_variable_as_pred_w_subj() {
    ecs_log_set_level(-4);

    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Src);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL == ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .id = EcsVariable, .src.id = Src }}
    }));

    ecs_fini(world);
}

void Filter_filter_1_variable_as_pred_w_pair() {
    ecs_log_set_level(-4);

    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Src);
    ECS_TAG(world, Tgt);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL == ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .first.id = EcsVariable, 
            .src.id = Src, 
            .second.id = Tgt 
        }}
    }));

    ecs_fini(world);
}

void Filter_filter_1_variable_as_subj() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Foo);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .first.id = Foo, 
            .src.id = EcsVariable,
            .src.flags = EcsIsVariable
        }}
    }));
    
    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, Foo);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Foo);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, Foo);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsEntity);
    test_int(f.terms[0].src.trav, EcsIsA);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_src_var() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Foo);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .first.id = Foo, 
            .src.flags = EcsIsVariable,
            .src.name = "Var"
        }}
    }));
    
    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, Foo);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Foo);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_str(f.terms[0].src.name, "Var");
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_first_var() {
    ecs_world_t *world = ecs_mini();

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .first.flags = EcsIsVariable,
            .first.name = "Var"
        }}
    }));
    
    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, EcsWildcard);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_str(f.terms[0].first.name, "Var");
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsVariable);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_second_var() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Foo);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .first.id = Foo,
            .second.flags = EcsIsVariable,
            .second.name = "Var"
        }}
    }));

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, ecs_pair(Foo, EcsWildcard));
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Foo);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);
    test_str(f.terms[0].second.name, "Var");
    test_int(f.terms[0].second.flags, EcsSelf|EcsIsVariable);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_variable_as_obj() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Foo);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .first.id = Foo, 
            .second.id = EcsVariable,
            .second.flags = EcsIsVariable
        }}
    }));
    
    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, ecs_pair(Foo, Foo));
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Foo);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);
    test_int(f.terms[0].second.id, Foo);
    test_int(f.terms[0].second.flags, EcsSelf|EcsIsEntity);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_2_terms_or_w_dontinherit() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_add_id(world, TagB, EcsDontInherit);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .terms = {{ TagA, .oper = EcsOr }, { TagB }}
    }));

    test_int(f.term_count, 2);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);

    test_int(f.terms[0].id, TagA);
    test_int(f.terms[0].oper, EcsOr);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, TagA);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);

    test_int(f.terms[1].id, TagB);
    test_int(f.terms[1].oper, EcsAnd);
    test_int(f.terms[1].field_index, 0);
    test_int(f.terms[1].first.id, TagB);
    test_int(f.terms[1].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[1].src.id, EcsThis);
    test_int(f.terms[1].src.flags, EcsSelf|EcsIsVariable);
    test_int(f.terms[1].src.trav, 0);
    
    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_2_terms_or_w_both_dontinherit() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_add_id(world, TagA, EcsDontInherit);
    ecs_add_id(world, TagB, EcsDontInherit);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .terms = {{ TagA, .oper = EcsOr }, { TagB }}
    }));

    test_int(f.term_count, 2);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);

    test_int(f.terms[0].id, TagA);
    test_int(f.terms[0].oper, EcsOr);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, TagA);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsIsVariable);
    test_int(f.terms[0].src.trav, 0);

    test_int(f.terms[1].id, TagB);
    test_int(f.terms[1].oper, EcsAnd);
    test_int(f.terms[1].field_index, 0);
    test_int(f.terms[1].first.id, TagB);
    test_int(f.terms[1].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[1].src.id, EcsThis);
    test_int(f.terms[1].src.flags, EcsSelf|EcsIsVariable);
    test_int(f.terms[1].src.trav, 0);
    
    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_pair_id() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Tgt);

    ecs_id_t pair = ecs_pair(Rel, Tgt);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{pair}}
    });

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, pair);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Rel);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);
    test_int(f.terms[0].second.id, Tgt);
    test_int(f.terms[0].second.flags, EcsSelf|EcsIsEntity);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_pred_obj() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Tgt);

    ecs_id_t pair = ecs_pair(Rel, Tgt);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{.first.id = Rel, .second.id = Tgt}}
    }));

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, pair);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Rel);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].second.id, Tgt);
    test_int(f.terms[0].second.flags, EcsSelf|EcsIsEntity);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_pair_id_and_subj() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Tgt);
    ECS_TAG(world, Src);

    ecs_id_t pair = ecs_pair(Rel, Tgt);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{.id = pair, .src.id = Src}}
    }));

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, pair);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, Rel);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, Src);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsEntity);
    test_int(f.terms[0].second.id, Tgt);
    test_int(f.terms[0].second.flags, EcsSelf|EcsIsEntity);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_term_w_id() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_term_t term = {
        .id = Tag
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, Tag);
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsVariable);

    ecs_fini(world);
}

void Filter_term_w_pair_id() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Tgt);

    ecs_id_t pair = ecs_pair(Rel, Tgt);

    ecs_term_t term = {
        .id = pair
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, pair);
    test_int(term.id_flags, ECS_PAIR);
    test_int(term.first.id, Rel);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(term.second.id, Tgt);
    test_int(term.second.flags, EcsSelf|EcsIsEntity);

    ecs_fini(world);
}

void Filter_term_w_pred_obj() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Tgt);

    ecs_id_t pair = ecs_pair(Rel, Tgt);

    ecs_term_t term = {
        .first.id = Rel,
        .second.id = Tgt
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, pair);
    test_int(term.id_flags, ECS_PAIR);
    test_int(term.first.id, Rel);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(term.second.id, Tgt);
    test_int(term.second.flags, EcsSelf|EcsIsEntity);

    ecs_fini(world);
}

void Filter_term_w_pair_finalize_twice() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Tgt);

    ecs_id_t pair = ecs_pair(Rel, Tgt);

    ecs_term_t term = {
        .first.id = Rel,
        .second.id = Tgt
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, pair);
    test_int(term.id_flags, ECS_PAIR);
    test_int(term.first.id, Rel);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(term.second.id, Tgt);
    test_int(term.second.flags, EcsSelf|EcsIsEntity);

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, pair);
    test_int(term.id_flags, ECS_PAIR);
    test_int(term.first.id, Rel);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(term.second.id, Tgt);
    test_int(term.second.flags, EcsSelf|EcsIsEntity);

    ecs_fini(world);
}

void Filter_term_w_role() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_term_t term = {
        .id = Tag,
        .id_flags = ECS_OVERRIDE
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, Tag | ECS_OVERRIDE);
    test_int(term.id_flags, ECS_OVERRIDE);
    test_int(term.first.id, Tag);

    test_int(term.id, Tag | ECS_OVERRIDE);
    test_int(term.id_flags, ECS_OVERRIDE);
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsVariable);

    ecs_fini(world);
}

void Filter_term_w_pred_role() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_term_t term = {
        .first.id = Tag,
        .id_flags = ECS_OVERRIDE
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id_flags, ECS_OVERRIDE);
    test_int(term.id, Tag | ECS_OVERRIDE);
    test_int(term.id_flags, ECS_OVERRIDE);
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsVariable);

    ecs_fini(world);
}

void Filter_term_w_self() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_term_t term = {
        .first.id = Tag,
        .src.flags = EcsSelf
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, Tag);
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsIsVariable);

    ecs_fini(world);
}

void Filter_term_w_superset() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_term_t term = {
        .first.id = Tag,
        .src.flags = EcsUp
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, Tag);
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsUp|EcsIsVariable);
    test_int(term.src.trav, EcsIsA);

    ecs_fini(world);
}

void Filter_term_w_subset() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_term_t term = {
        .first.id = Tag,
        .src.flags = EcsDown
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, Tag);
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsDown|EcsIsVariable);
    test_int(term.src.trav, EcsIsA);

    ecs_fini(world);
}

void Filter_term_w_self_superset() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_term_t term = {
        .first.id = Tag,
        .src.flags = EcsSelf | EcsUp
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, Tag);
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(term.src.trav, EcsIsA);

    ecs_fini(world);
}

void Filter_term_w_superset_custom_relation() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_term_t term = {
        .first.id = Tag,
        .src.flags = EcsUp,
        .src.trav = EcsChildOf
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, Tag);
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsUp|EcsIsVariable);
    test_int(term.src.trav, EcsChildOf);

    ecs_fini(world);
}

void Filter_term_w_self_superset_custom_relation() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_term_t term = {
        .first.id = Tag,
        .src.flags = EcsSelf | EcsUp,
        .src.trav = EcsChildOf
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, Tag);
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(term.src.trav, EcsChildOf);

    ecs_fini(world);
}

void Filter_filter_1_w_pred_name() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_term_t term = {
        .first.name = "Tag"
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, Tag);
    test_int(term.first.id, Tag);
    test_assert(term.first.name ==  NULL);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(term.src.trav, EcsIsA);

    ecs_fini(world);
}

void Filter_filter_1_w_final_pred_name() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Tag, Final);

    ecs_term_t term = {
        .first.name = "Tag"
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, Tag);
    test_int(term.first.id, Tag);
    test_assert(term.first.name ==  NULL);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.first.trav, 0);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(term.src.trav, EcsIsA);

    ecs_fini(world);
}

void Filter_filter_1_w_subj_name() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);
    ECS_TAG(world, Src);

    ecs_term_t term = {
        .first.id = Tag,
        .src.name = "Src"
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, Tag);
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, Src);
    test_assert(term.src.name ==  NULL);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsEntity);
    test_int(term.src.trav, EcsIsA);

    ecs_fini(world);
}

void Filter_filter_1_w_obj_name() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);
    ECS_TAG(world, Tgt);

    ecs_term_t term = {
        .first.id = Tag,
        .second.name = "Tgt"
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, ecs_pair(Tag, Tgt));
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(term.src.trav, EcsIsA);
    test_int(term.second.id, Tgt);
    test_assert(term.second.name ==  NULL);
    test_int(term.second.flags, EcsSelf|EcsIsEntity);

    ecs_fini(world);
}

void Filter_filter_w_this_implicit_variable() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_term_t term = {
        .first.id = Tag,
        .src.id = EcsThis
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, Tag);
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(term.src.trav, EcsIsA);

    ecs_fini(world);
}

void Filter_filter_w_this_explicit_entity() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_term_t term = {
        .first.id = Tag,
        .src.id = EcsThis,
        .src.flags = EcsIsEntity
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, Tag);
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsEntity);
    test_int(term.src.trav, EcsIsA);

    ecs_fini(world);
}

void Filter_filter_w_first_this_implicit_variable() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Src);

    ecs_term_t term = {
        .first.id = EcsThis,
        .src.id = Src
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, EcsWildcard);
    test_int(term.first.id, EcsThis);
    test_int(term.first.flags, EcsSelf|EcsIsVariable);
    test_int(term.src.id, Src);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsEntity);
    test_int(term.src.trav, EcsIsA);

    ecs_fini(world);
}

void Filter_filter_w_first_this_explicit_entity() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Src);

    ecs_term_t term = {
        .first.id = EcsThis,
        .first.flags = EcsIsEntity,
        .src.id = Src
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, EcsThis);
    test_int(term.first.id, EcsThis);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, Src);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsEntity);
    test_int(term.src.trav, EcsIsA);

    ecs_fini(world);
}

void Filter_filter_w_second_this_implicit_variable() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_term_t term = {
        .first.id = Tag,
        .second.id = EcsThis
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, ecs_pair(Tag, EcsWildcard));
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(term.src.trav, EcsIsA);
    test_int(term.second.id, EcsThis);
    test_int(term.second.flags, EcsSelf|EcsIsVariable);

    ecs_fini(world);
}

void Filter_filter_w_second_this_explicit_entity() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_term_t term = {
        .first.id = Tag,
        .second.id = EcsThis,
        .second.flags = EcsIsEntity
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, ecs_pair(Tag, EcsThis));
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(term.src.trav, EcsIsA);
    test_int(term.second.id, EcsThis);
    test_int(term.second.flags, EcsSelf|EcsIsEntity);

    ecs_fini(world);
}

void Filter_filter_w_this_variable_name() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_term_t term = {
        .first.id = Tag,
        .src.name = "This",
        .src.flags = EcsIsVariable
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, Tag);
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(term.src.trav, EcsIsA);
    test_assert(term.src.name == NULL);

    ecs_fini(world);
}

void Filter_filter_w_0_source() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_term_t term = {
        .first.id = Tag,
        .src.flags = EcsIsEntity
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, Tag);
    test_int(term.first.id, Tag);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, 0);
    test_int(term.src.flags, EcsIsEntity);
    test_int(term.src.trav, 0);

    ecs_fini(world);
}

void Filter_filter_w_0_target() {
    ecs_world_t *world = ecs_mini();

    ecs_term_t term = {
        .first.id = EcsChildOf,
        .second.flags = EcsIsEntity
    };

    test_assert(ecs_term_finalize(world, &term) == 0);
    test_int(term.id, ecs_pair(EcsChildOf, 0));
    test_int(term.first.id, EcsChildOf);
    test_int(term.first.flags, EcsSelf|EcsIsEntity);
    test_int(term.src.id, EcsThis);
    test_int(term.src.flags, EcsSelf|EcsIsVariable);
    test_int(term.src.trav, 0);
    test_int(term.second.id, 0);
    test_int(term.second.flags, EcsIsEntity);
    test_int(term.second.trav, 0);

    ecs_fini(world);
}

void Filter_filter_2_terms_w_or() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{TagA, .oper = EcsOr}, {TagB }}
    }));

    test_int(f.terms[0].oper, EcsOr);
    test_int(f.terms[0].id, TagA);
    test_int(f.terms[0].first.id, TagA);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[0].src.trav, EcsIsA);

    test_int(f.terms[1].oper, EcsAnd);
    test_int(f.terms[1].id, TagB);
    test_int(f.terms[1].first.id, TagB);
    test_int(f.terms[1].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[1].src.id, EcsThis);
    test_int(f.terms[1].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f.terms[1].src.trav, EcsIsA);
    
    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_2_terms_w_or_mixed_src_flags() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {TagA, .oper = EcsOr}, 
            {TagB, .oper = EcsAnd, .src.flags = EcsUp}
        }
    }));

    ecs_entity_t base = ecs_new(world, TagB);
    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_entity_t e2 = ecs_new_w_pair(world, EcsIsA, base);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(TagA, it.ids[0]);
    test_uint(0, it.sources[0]);

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e2, it.entities[0]);
    test_uint(TagB, it.ids[0]);
    test_uint(base, it.sources[0]);

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_2_terms_w_or_mixed_src_id() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ECS_TAG(world, SrcA);
    ECS_TAG(world, SrcB);

    ecs_log_set_level(-4);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL == ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {TagA, .oper = EcsOr, .src.id = SrcA}, 
            {TagB, .oper = EcsOr, .src.id = SrcB}
        }
    }));

    ecs_fini(world);
}

void Filter_filter_2_terms_w_or_mixed_src_name() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ECS_TAG(world, SrcA);
    ECS_TAG(world, SrcB);

    ecs_log_set_level(-4);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL == ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {TagA, .oper = EcsOr, .src.name = "SrcA"}, 
            {TagB, .oper = EcsOr, .src.name = "SrcB"}
        }
    }));

    ecs_fini(world);
}

void Filter_filter_2_terms_w_or_same_src_w_id_and_name() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ECS_TAG(world, SrcA);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {TagA, .oper = EcsOr, .src.name = "SrcA"}, 
            {TagB, .src.id = SrcA}
        }
    }));

    test_int(f.terms[0].oper, EcsOr);
    test_int(f.terms[0].id, TagA);
    test_int(f.terms[0].first.id, TagA);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, SrcA);
    test_int(f.terms[0].src.flags, EcsSelf|EcsUp|EcsIsEntity);
    test_int(f.terms[0].src.trav, EcsIsA);

    test_int(f.terms[1].oper, EcsAnd);
    test_int(f.terms[1].id, TagB);
    test_int(f.terms[1].first.id, TagB);
    test_int(f.terms[1].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[1].src.id, SrcA);
    test_int(f.terms[1].src.flags, EcsSelf|EcsUp|EcsIsEntity);
    test_int(f.terms[1].src.trav, EcsIsA);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_move() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_filter_t f_1 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_1,
        .terms = {{TagA}, {TagB}}
    }));

    test_int(f_1.term_count, 2);
    test_assert(f_1.terms != NULL);
    test_int(f_1.terms[0].id, TagA);
    test_int(f_1.terms[1].id, TagB);

    ecs_filter_t f_2 = {0};
    ecs_filter_move(&f_2, &f_1);

    test_int(f_2.term_count, 2);
    test_assert(f_2.terms != NULL);
    test_int(f_2.terms[0].id, TagA);
    test_int(f_2.terms[1].id, TagB);

    test_int(f_1.term_count, 0);
    test_assert(f_1.terms == NULL);

    ecs_filter_fini(&f_1);
    ecs_filter_fini(&f_2);

    ecs_fini(world);
}

void Filter_filter_copy() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_filter_t f_1 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_1,
        .terms = {{TagA}, {TagB}}
    }));

    test_int(f_1.term_count, 2);
    test_assert(f_1.terms != NULL);
    test_int(f_1.terms[0].id, TagA);
    test_int(f_1.terms[1].id, TagB);

    ecs_filter_t f_2 = {0};
    ecs_filter_copy(&f_2, &f_1);

    test_int(f_1.term_count, 2);
    test_assert(f_1.terms != NULL);
    test_int(f_1.terms[0].id, TagA);
    test_int(f_1.terms[1].id, TagB);

    test_int(f_2.term_count, 2);
    test_assert(f_2.terms != NULL);
    test_int(f_2.terms[0].id, TagA);
    test_int(f_2.terms[1].id, TagB);

    test_assert(f_1.terms != f_2.terms);

    ecs_filter_fini(&f_1);
    ecs_filter_fini(&f_2);

    ecs_fini(world);
}

void Filter_filter_w_resources_copy() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_filter_t f_1 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_1,
        .terms = {{TagA, .src.name = "this"}, {TagB, .src.name = "this"}}
    }));

    test_int(f_1.term_count, 2);
    test_assert(f_1.terms != NULL);
    test_int(f_1.terms[0].id, TagA);
    test_int(f_1.terms[1].id, TagB);

    ecs_filter_t f_2 = {0};
    ecs_filter_copy(&f_2, &f_1);

    test_int(f_1.term_count, 2);
    test_assert(f_1.terms != NULL);
    test_int(f_1.terms[0].id, TagA);
    test_int(f_1.terms[1].id, TagB);

    test_int(f_2.term_count, 2);
    test_assert(f_2.terms != NULL);
    test_int(f_2.terms[0].id, TagA);
    test_int(f_2.terms[1].id, TagB);

    test_assert(f_1.terms != f_2.terms);

    ecs_filter_fini(&f_1);
    ecs_filter_fini(&f_2);

    ecs_fini(world);
}

void Filter_filter_w_and_flag() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {ECS_AND | TagA}
        }
    }));

    test_int(f.term_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, TagA);
    test_int(f.terms[0].id_flags, 0);
    test_int(f.terms[0].oper, EcsAndFrom);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_or_flag() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { TagA, .oper = EcsOrFrom }
        }
    }));

    test_int(f.term_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, TagA);
    test_int(f.terms[0].id_flags, 0);
    test_int(f.terms[0].oper, EcsOrFrom);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_filter() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {TagA}
        },
        .flags = EcsFilterNoData
    }));

    test_int(f.term_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, TagA);
    test_int(f.terms[0].id_flags, 0);
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].inout, EcsInOutNone);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_double_init() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Foo);

    ecs_filter_t f_1 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_1,
        .terms = {{ Foo }}
    }));

    test_int(f_1.term_count, 1);
    test_int(f_1.terms[0].id, Foo);
    test_int(f_1.terms[0].oper, EcsAnd);
    test_int(f_1.terms[0].field_index, 0);
    test_int(f_1.terms[0].first.id, Foo);
    test_int(f_1.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f_1.terms[0].src.id, EcsThis);
    test_int(f_1.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f_1.terms[0].src.trav, EcsIsA);

    ecs_filter_t f_2 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_2,
        .terms_buffer = f_1.terms,
        .terms_buffer_count = 1
    }));

    test_int(f_2.term_count, 1);
    test_int(f_2.terms[0].id, Foo);
    test_int(f_2.terms[0].oper, EcsAnd);
    test_int(f_2.terms[0].field_index, 0);
    test_int(f_2.terms[0].first.id, Foo);
    test_int(f_2.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f_2.terms[0].src.id, EcsThis);
    test_int(f_2.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f_2.terms[0].src.trav, EcsIsA);

    ecs_filter_fini(&f_1);
    ecs_filter_fini(&f_2);

    ecs_fini(world);
}

void Filter_filter_double_init_w_expr() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Foo);

    ecs_filter_t f_1 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_1,
        .expr = "Foo"
    }));

    test_int(f_1.term_count, 1);
    test_int(f_1.terms[0].id, Foo);
    test_int(f_1.terms[0].oper, EcsAnd);
    test_int(f_1.terms[0].field_index, 0);
    test_int(f_1.terms[0].first.id, Foo);
    test_int(f_1.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f_1.terms[0].src.id, EcsThis);
    test_int(f_1.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f_1.terms[0].src.trav, EcsIsA);

    ecs_filter_t f_2 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_2,
        .terms_buffer = f_1.terms,
        .terms_buffer_count = 1
    }));

    test_int(f_2.term_count, 1);
    test_int(f_2.terms[0].id, Foo);
    test_int(f_2.terms[0].oper, EcsAnd);
    test_int(f_2.terms[0].field_index, 0);
    test_int(f_2.terms[0].first.id, Foo);
    test_int(f_2.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f_2.terms[0].src.id, EcsThis);
    test_int(f_2.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f_2.terms[0].src.trav, EcsIsA);

    ecs_filter_fini(&f_1);
    ecs_filter_fini(&f_2);

    ecs_fini(world);
}

void Filter_filter_double_init_w_expr_optional() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Foo);

    ecs_filter_t f_1 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_1,
        .expr = "?Foo"
    }));

    test_int(f_1.term_count, 1);
    test_int(f_1.terms[0].id, Foo);
    test_int(f_1.terms[0].oper, EcsOptional);
    test_int(f_1.terms[0].field_index, 0);
    test_int(f_1.terms[0].first.id, Foo);
    test_int(f_1.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f_1.terms[0].src.id, EcsThis);
    test_int(f_1.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f_1.terms[0].src.trav, EcsIsA);

    ecs_filter_t f_2 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_2,
        .terms_buffer = f_1.terms,
        .terms_buffer_count = 1
    }));

    test_int(f_2.term_count, 1);
    test_int(f_2.terms[0].id, Foo);
    test_int(f_2.terms[0].oper, EcsOptional);
    test_int(f_2.terms[0].field_index, 0);
    test_int(f_2.terms[0].first.id, Foo);
    test_int(f_2.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f_2.terms[0].src.id, EcsThis);
    test_int(f_2.terms[0].src.flags, EcsSelf|EcsUp|EcsIsVariable);
    test_int(f_2.terms[0].src.trav, EcsIsA);

    ecs_filter_fini(&f_1);
    ecs_filter_fini(&f_2);

    ecs_fini(world);
}

void Filter_filter_w_tag_term_is_no_data() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Foo);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ Foo }}
    }));

    test_assert(f.flags & EcsFilterNoData);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_assert(it.flags & EcsIterNoData);
    ecs_iter_fini(&it);

    ecs_filter_fini(&f);

    ecs_fini(world);   
}

void Filter_filter_w_inout_none_term_is_no_data() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ ecs_id(Position), .inout = EcsInOutNone }}
    }));

    test_assert(f.flags & EcsFilterNoData);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_assert(it.flags & EcsIterNoData);
    ecs_iter_fini(&it);

    ecs_filter_fini(&f);

    ecs_fini(world);  
}

void Filter_filter_w_tag_and_inout_none_term_is_no_data() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_TAG(world, Foo);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { ecs_id(Position), .inout = EcsInOutNone },
            { Foo }
        }
    }));

    test_assert(f.flags & EcsFilterNoData);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_assert(it.flags & EcsIterNoData);
    ecs_iter_fini(&it);

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_not_term_is_no_data() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_TAG(world, Foo);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { ecs_id(Position), .oper = EcsNot }
        }
    }));

    test_assert(f.flags & EcsFilterNoData);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_assert(it.flags & EcsIterNoData);
    ecs_iter_fini(&it);

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_no_transitive_pair() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, LocatedIn);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .first.id = LocatedIn, .second.id = EcsWildcard }
        }
    }));

    test_assert(!(f.terms[0].flags & EcsTermTransitive));

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_transitive_pair_any_src() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, LocatedIn, Transitive);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {
                .first.id = LocatedIn, 
                .second.id = EcsWildcard,
                .src.id = EcsAny
            }
        }
    }));

    test_assert(!(f.terms[0].flags & EcsTermTransitive));

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_transitive_pair() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, LocatedIn, Transitive);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .first.id = LocatedIn, .second.id = EcsWildcard }
        }
    }));

    test_assert(f.terms[0].flags & EcsTermTransitive);

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_transitive_tag_no_pair() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, LocatedIn, Transitive);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .first.id = LocatedIn }
        }
    }));

    test_assert(!(f.terms[0].flags & EcsTermTransitive));

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_transitive_tag_self_tgt() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, LocatedIn, Transitive);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .first.id = LocatedIn, .second.id = EcsWildcard, .second.flags = EcsSelf }
        }
    }));

    test_assert(!(f.terms[0].flags & EcsTermTransitive));

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_transitive_tag_any_tgt() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, LocatedIn, Transitive);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .first.id = LocatedIn, .second.id = EcsAny }
        }
    }));

    test_assert(!(f.terms[0].flags & EcsTermTransitive));

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_pair_same_vars() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {
                .first.id = Rel, 
                .src.name = "a",
                .src.flags = EcsIsVariable,
                .second.name = "a",
                .second.flags = EcsIsVariable,
            }
        }
    }));

    test_assert(f.terms[0].src.flags & EcsIsVariable);
    test_assert(f.terms[0].second.flags & EcsIsVariable);
    test_str(f.terms[0].src.name, "a");
    test_str(f.terms[0].second.name, "a");
    test_assert(f.terms[0].flags & EcsTermSrcSecondEq);

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_pair_not_same_vars() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {
                .first.id = Rel, 
                .src.name = "a",
                .src.flags = EcsIsVariable,
                .second.name = "b",
                .second.flags = EcsIsVariable,
            }
        }
    }));

    test_assert(f.terms[0].src.flags & EcsIsVariable);
    test_assert(f.terms[0].second.flags & EcsIsVariable);
    test_str(f.terms[0].src.name, "a");
    test_str(f.terms[0].second.name, "b");
    test_assert(!(f.terms[0].flags & EcsTermSrcSecondEq));

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_pair_no_vars_not_same_vars() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, A);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {
                .first.id = Rel, 
                .src.id = A,
                .second.id = A
            }
        }
    }));

    test_assert(f.terms[0].src.flags & EcsIsEntity);
    test_assert(f.terms[0].second.flags & EcsIsEntity);
    test_uint(f.terms[0].src.id, A);
    test_uint(f.terms[0].second.id, A);
    test_assert(f.terms[0].flags & EcsTermSrcSecondEq);

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_pair_wildcard_not_same_vars() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {
                .first.id = Rel, 
                .src.id = EcsWildcard,
                .second.id = EcsWildcard
            }
        }
    }));

    test_assert(f.terms[0].src.flags & EcsIsVariable);
    test_assert(f.terms[0].second.flags & EcsIsVariable);
    test_uint(f.terms[0].src.id, EcsWildcard);
    test_uint(f.terms[0].second.id, EcsWildcard);
    test_assert(!(f.terms[0].flags & EcsTermSrcSecondEq));

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_pair_any_not_same_vars() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {
                .first.id = Rel, 
                .src.id = EcsAny,
                .second.id = EcsAny
            }
        }
    }));

    test_assert(f.terms[0].src.flags & EcsIsVariable);
    test_assert(f.terms[0].second.flags & EcsIsVariable);
    test_uint(f.terms[0].src.id, EcsAny);
    test_uint(f.terms[0].second.id, EcsAny);
    test_assert(!(f.terms[0].flags & EcsTermSrcSecondEq));

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_no_pair_not_same_vars() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {
                .first.id = Rel, 
                .src.name = "a",
                .src.flags = EcsIsVariable
            }
        }
    }));

    test_assert(f.terms[0].src.flags & EcsIsVariable);
    test_assert(!(f.terms[0].second.flags & EcsIsVariable));
    test_str(f.terms[0].src.name, "a");
    test_assert(!(f.terms[0].flags & EcsTermSrcSecondEq));

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_not_childof_any() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {
                .first.id = EcsChildOf, 
                .second.id = EcsAny,
                .oper = EcsNot
            }
        }
    }));

    test_int(f.term_count, 1);
    test_int(f.field_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, ecs_pair(EcsChildOf, 0));
    test_int(f.terms[0].oper, EcsAnd);
    test_int(f.terms[0].inout, EcsInOutDefault);
    test_int(f.terms[0].field_index, 0);
    test_int(f.terms[0].first.id, EcsChildOf);
    test_int(f.terms[0].first.flags, EcsSelf|EcsIsEntity);
    test_int(f.terms[0].src.id, EcsThis);
    test_int(f.terms[0].src.flags, EcsSelf|EcsIsVariable);
    test_int(f.terms[0].second.id, 0);
    test_int(f.terms[0].second.flags, EcsSelf|EcsIsEntity);

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_inherited_id() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Unit);
    ECS_ENTITY(world, MeleeUnit, (IsA, Unit));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .terms = {
            { .first.id = Unit }
        }
    }));

    test_assert(f.terms[0].flags & EcsTermIdInherited);
    test_int(f.terms[0].first.trav, EcsIsA);
    test_int(f.terms[0].first.id, Unit);

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_inherited_pair() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Unit);
    ECS_ENTITY(world, MeleeUnit, (IsA, Unit));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .terms = {
            { .first.id = Unit, .second.id = EcsWildcard }
        }
    }));

    test_assert(f.terms[0].flags & EcsTermIdInherited);
    test_int(f.terms[0].first.trav, EcsIsA);
    test_int(f.terms[0].first.id, Unit);
    test_int(f.terms[0].second.id, EcsWildcard);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_non_inherited_id() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Unit);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .terms = {
            { .first.id = Unit }
        }
    }));

    test_assert(!(f.terms[0].flags & EcsTermIdInherited));

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_non_inherited_pair() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Unit);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .terms = {
            { .first.id = Unit, .second.id = EcsWildcard }
        }
    }));

    test_assert(!(f.terms[0].flags & EcsTermIdInherited));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_first_rel() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Rel, Traversable);
    ECS_TAG(world, Unit);
    ECS_ENTITY(world, MeleeUnit, (Rel, Unit));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .terms = {
            { .first.id = Unit, .first.trav = Rel }
        }
    }));

    test_assert(f.terms[0].flags & EcsTermIdInherited);
    test_int(f.terms[0].first.trav, Rel);
    test_int(f.terms[0].first.id, Unit);
    test_int(f.terms[0].first.flags, EcsDown|EcsIsEntity);

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_first_rel_self() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Rel, Traversable);
    ECS_TAG(world, Unit);
    ECS_ENTITY(world, MeleeUnit, (Rel, Unit));

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_log_set_level(-4);
    test_assert(NULL == ecs_filter(world, {
        .storage = &f,
        .terms = {
            { .first.id = Unit, .first.flags = EcsSelf, .first.trav = Rel }
        }
    }));

    ecs_fini(world); 
}

void Filter_filter_w_first_rel_down() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Rel, Traversable);
    ECS_TAG(world, Unit);
    ECS_ENTITY(world, MeleeUnit, (Rel, Unit));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .terms = {
            { .first.id = Unit, .first.flags = EcsDown, .first.trav = Rel }
        }
    }));

    test_assert(f.terms[0].flags & EcsTermIdInherited);
    test_int(f.terms[0].first.trav, Rel);
    test_int(f.terms[0].first.id, Unit);
    test_int(f.terms[0].first.flags, EcsDown|EcsIsEntity);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_first_rel_self_down() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Rel, Traversable);
    ECS_TAG(world, Unit);
    ECS_ENTITY(world, MeleeUnit, (Rel, Unit));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .terms = {
            { .first.id = Unit, .first.flags = EcsSelf|EcsDown, .first.trav = Rel }
        }
    }));

    test_assert(f.terms[0].flags & EcsTermIdInherited);
    test_int(f.terms[0].first.trav, Rel);
    test_int(f.terms[0].first.id, Unit);
    test_int(f.terms[0].first.flags, EcsSelf|EcsDown|EcsIsEntity);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_first_rel_reflexive() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Rel, Traversable, Reflexive);
    ECS_TAG(world, Unit);
    ECS_ENTITY(world, MeleeUnit, (Rel, Unit));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .terms = {
            { .first.id = Unit, .first.trav = Rel }
        }
    }));

    test_assert(f.terms[0].flags & EcsTermIdInherited);
    test_int(f.terms[0].first.trav, Rel);
    test_int(f.terms[0].first.id, Unit);
    test_int(f.terms[0].first.flags, EcsSelf|EcsDown|EcsIsEntity);

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_first_rel_reflexive_self() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Rel, Traversable, Reflexive);
    ECS_TAG(world, Unit);
    ECS_ENTITY(world, MeleeUnit, (Rel, Unit));

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_log_set_level(-4);
    test_assert(NULL == ecs_filter(world, {
        .storage = &f,
        .terms = {
            { .first.id = Unit, .first.flags = EcsSelf, .first.trav = Rel }
        }
    }));

    ecs_fini(world); 
}

void Filter_filter_w_first_rel_reflexive_down() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Rel, Traversable, Reflexive);
    ECS_TAG(world, Unit);
    ECS_ENTITY(world, MeleeUnit, (Rel, Unit));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .terms = {
            { .first.id = Unit, .first.flags = EcsDown, .first.trav = Rel }
        }
    }));

    test_assert(f.terms[0].flags & EcsTermIdInherited);
    test_int(f.terms[0].first.trav, Rel);
    test_int(f.terms[0].first.id, Unit);
    test_int(f.terms[0].first.flags, EcsDown|EcsIsEntity);

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_first_rel_reflexive_self_down() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Rel, Traversable, Reflexive);
    ECS_TAG(world, Unit);
    ECS_ENTITY(world, MeleeUnit, (Rel, Unit));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .terms = {
            { .first.id = Unit, .first.flags = EcsSelf|EcsDown, .first.trav = Rel }
        }
    }));

    test_assert(f.terms[0].flags & EcsTermIdInherited);
    test_int(f.terms[0].first.trav, Rel);
    test_int(f.terms[0].first.id, Unit);
    test_int(f.terms[0].first.flags, EcsSelf|EcsDown|EcsIsEntity);

    ecs_filter_fini(&f);

    ecs_fini(world); 
}

void Filter_filter_w_first_rel_non_traversable() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Unit);

    ecs_log_set_level(-4);
    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL == ecs_filter(world, {
        .storage = &f,
        .terms = {
            { .first.id = Unit, .first.trav = Rel }
        }
    }));

    ecs_fini(world); 
}

void Filter_filter_w_first_wildcard_inout_none() {
    ecs_world_t *world = ecs_mini();

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .terms = {
            { .first.id = EcsWildcard }
        }
    }));


    test_int(f.terms[0].inout, EcsInOutNone);

    ecs_fini(world);
}

void Filter_filter_w_first_var_inout_none() {
    ecs_world_t *world = ecs_mini();

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .terms = {
            { .first.name = "var", .first.flags = EcsIsVariable }
        }
    }));


    test_int(f.terms[0].inout, EcsInOutNone);

    ecs_fini(world);
}

void Filter_filter_w_pair_wildcard_inout_none() {
    ecs_world_t *world = ecs_mini();

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .terms = {
            { .first.id = EcsWildcard, .second.id = EcsWildcard }
        }
    }));


    test_int(f.terms[0].inout, EcsInOutNone);

    ecs_fini(world);
}

void Filter_filter_w_pair_var_inout_none() {
    ecs_world_t *world = ecs_mini();

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .terms = {
            {
                .first.name = "x", .first.flags = EcsIsVariable,
                .second.name = "y", .second.flags = EcsIsVariable,
            }
        }
    }));

    test_int(f.terms[0].inout, EcsInOutNone);

    ecs_fini(world);
}

void Filter_filter_w_unresolved_by_name() {
    ecs_world_t *world = ecs_mini();

    ecs_log_set_level(-4);
    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL == ecs_filter(world, {
        .storage = &f,
        .terms = { { .first.name = "Foo" } },
        .flags = EcsFilterUnresolvedByName
    }));

    ecs_fini(world);
}

void Filter_filter_w_unresolved_by_name_eq() {
    ecs_world_t *world = ecs_mini();

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter(world, {
        .storage = &f,
        .expr = "$this == Foo",
        .flags = EcsFilterUnresolvedByName
    }));

    test_assert(f.terms[0].second.flags & EcsIsName);
    test_str(f.terms[0].second.name, "Foo");

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_not_flag() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { TagA, .oper = EcsNotFrom }
        }
    }));

    test_int(f.term_count, 1);
    test_assert(f.terms != NULL);
    test_int(f.terms[0].id, TagA);
    test_int(f.terms[0].id_flags, 0);
    test_int(f.terms[0].oper, EcsNotFrom);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_term_iter_component() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_set(world, 0, Position, {1, 2});
    ecs_entity_t e_2 = ecs_set(world, 0, Position, {3, 4});
    ecs_entity_t e_3 = ecs_set(world, 0, Position, {5, 6});

    ecs_add(world, e_3, Tag);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) {
        ecs_id(Position)
    });

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));

    Position *p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p[0].x, 1);
    test_int(p[0].y, 2);

    test_int(p[1].x, 3);
    test_int(p[1].y, 4);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));

    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p[0].x, 5);
    test_int(p[0].y, 6);

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_w_pred() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_set(world, 0, Position, {1, 2});
    ecs_entity_t e_2 = ecs_set(world, 0, Position, {3, 4});
    ecs_entity_t e_3 = ecs_set(world, 0, Position, {5, 6});

    ecs_add(world, e_3, Tag);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) {
        .first.id = ecs_id(Position)
    });

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));

    Position *p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p[0].x, 1);
    test_int(p[0].y, 2);

    test_int(p[1].x, 3);
    test_int(p[1].y, 4);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));

    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p[0].x, 5);
    test_int(p[0].y, 6);

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_tag() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag1);
    ECS_TAG(world, Tag2);

    ecs_entity_t e_1 = ecs_new(world, Tag1);
    ecs_entity_t e_2 = ecs_new(world, Tag1);
    ecs_entity_t e_3 = ecs_new(world, Tag1);

    ecs_add(world, e_3, Tag2);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) { Tag1 });

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), Tag1);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), Tag1);

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_pair() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Tgt);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_new_w_pair(world, Rel, Tgt);
    ecs_entity_t e_2 = ecs_new_w_pair(world, Rel, Tgt);
    ecs_entity_t e_3 = ecs_new_w_pair(world, Rel, Tgt);

    ecs_add(world, e_3, Tag);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) { ecs_pair(Rel, Tgt) });

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Tgt));

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Tgt));
    
    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_pair_w_rel_wildcard() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel_1);
    ECS_TAG(world, Rel_2);
    ECS_TAG(world, Tgt);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_new_w_pair(world, Rel_1, Tgt);
    ecs_entity_t e_2 = ecs_new_w_pair(world, Rel_1, Tgt);
    ecs_entity_t e_3 = ecs_new_w_pair(world, Rel_2, Tgt);

    ecs_add(world, e_3, Tag);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) { 
        ecs_pair(EcsWildcard, Tgt) 
    });

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Tgt));

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_2, Tgt));

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_pair_w_obj_wildcard() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Obj_1);
    ECS_TAG(world, Obj_2);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_new_w_pair(world, Rel, Obj_1);
    ecs_entity_t e_2 = ecs_new_w_pair(world, Rel, Obj_1);
    ecs_entity_t e_3 = ecs_new_w_pair(world, Rel, Obj_2);

    ecs_add(world, e_3, Tag);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) { 
        ecs_pair(Rel, EcsWildcard) 
    });

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Obj_1));

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Obj_2));

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_pair_w_rel_wildcard_n_matches() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel_1);
    ECS_TAG(world, Rel_2);
    ECS_TAG(world, Obj_1);
    ECS_TAG(world, Obj_2);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_new_w_pair(world, Rel_1, Obj_1);
    ecs_entity_t e_2 = ecs_new_w_pair(world, Rel_1, Obj_1);
    ecs_entity_t e_3 = ecs_new_w_pair(world, Rel_1, Obj_1);
    ecs_entity_t e_4 = ecs_new_w_pair(world, Rel_1, Obj_1);

    /* Add 2nd object for pair to ensure pairs for Obj_1 are separated */
    ecs_add_pair(world, e_3, Rel_1, Obj_2);
    ecs_add_pair(world, e_4, Rel_1, Obj_2);

    ecs_add_pair(world, e_3, Rel_2, Obj_1);
    ecs_add_pair(world, e_4, Rel_2, Obj_1);

    ecs_add(world, e_4, Tag);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) { 
        ecs_pair(EcsWildcard, Obj_1)
    });

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_2, Obj_1));

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_2, Obj_1));

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_pair_w_rel_wildcard_n_matches_w_data() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_TAG(world, Rel_1);
    ECS_TAG(world, Rel_2);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_set_pair_object(world, 0, Rel_1, Position, {10, 20});
    ecs_entity_t e_2 = ecs_set_pair_object(world, 0, Rel_1, Position, {10, 20});
    ecs_entity_t e_3 = ecs_set_pair_object(world, 0, Rel_1, Position, {10, 20});
    ecs_entity_t e_4 = ecs_set_pair_object(world, 0, Rel_1, Position, {10, 20});

    ecs_set_pair_object(world, e_3, Rel_2, Position, {20, 30});
    ecs_set_pair_object(world, e_4, Rel_2, Position, {20, 30});

    ecs_add(world, e_4, Tag);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) { 
        ecs_pair(EcsWildcard, ecs_id(Position)) 
    });

    const Position *p;

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, ecs_id(Position)));
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, ecs_id(Position)));
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_2, ecs_id(Position)));
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 20);
    test_int(p->y, 30);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, ecs_id(Position)));
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_2, ecs_id(Position)));
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 20);
    test_int(p->y, 30);

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_pair_w_obj_wildcard_n_matches() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Obj_1);
    ECS_TAG(world, Obj_2);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_new_w_pair(world, Rel, Obj_1);
    ecs_entity_t e_2 = ecs_new_w_pair(world, Rel, Obj_1);
    ecs_entity_t e_3 = ecs_new_w_pair(world, Rel, Obj_1);
    ecs_entity_t e_4 = ecs_new_w_pair(world, Rel, Obj_1);

    ecs_add_pair(world, e_3, Rel, Obj_2);
    ecs_add_pair(world, e_4, Rel, Obj_2);

    ecs_add(world, e_4, Tag);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) { 
        ecs_pair(Rel, EcsWildcard) 
    });

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Obj_1));

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Obj_1));

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Obj_2));

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Obj_1));

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Obj_2));

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_pair_w_obj_wildcard_n_matches_w_data() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_TAG(world, Obj_1);
    ECS_TAG(world, Obj_2);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_set_pair(world, 0, Position, Obj_1, {10, 20});
    ecs_entity_t e_2 = ecs_set_pair(world, 0, Position, Obj_1, {10, 20});
    ecs_entity_t e_3 = ecs_set_pair(world, 0, Position, Obj_1, {10, 20});
    ecs_entity_t e_4 = ecs_set_pair(world, 0, Position, Obj_1, {10, 20});

    ecs_set_pair(world, e_3, Position, Obj_2, {20, 30});
    ecs_set_pair(world, e_4, Position, Obj_2, {20, 30});

    ecs_add(world, e_4, Tag);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) { 
        ecs_pair(ecs_id(Position), EcsWildcard) 
    });

    const Position *p;

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(ecs_id(Position), Obj_1));
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(ecs_id(Position), Obj_1));
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(ecs_id(Position), Obj_2));
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 20);
    test_int(p->y, 30);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(ecs_id(Position), Obj_1));
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(ecs_id(Position), Obj_2));
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 20);
    test_int(p->y, 30);

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_w_superset() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_TAG(world, Tag);

    ecs_entity_t base = ecs_set(world, 0, Position, {10, 20});
    ecs_entity_t e_1 = ecs_new_w_pair(world, EcsIsA, base);
    ecs_entity_t e_2 = ecs_new_w_pair(world, EcsIsA, base);
    ecs_entity_t e_3 = ecs_new_w_pair(world, EcsIsA, base);

    ecs_add_id(world, e_3, Tag);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) {
        .id = ecs_id(Position),
        .src.flags = EcsUp
    });

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1), base);

    Position *ptr = ecs_field(&it, Position, 1);
    test_int(ptr->x, 10);
    test_int(ptr->y, 20);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1), base);

    test_assert(ptr == ecs_field(&it, Position, 1));

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_w_superset_base_w_2_components() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Velocity);
    ECS_COMPONENT(world, Position);
    ECS_TAG(world, Tag);

    ecs_entity_t base = ecs_set(world, 0, Position, {10, 20});
    ecs_set(world, base, Velocity, {0, 0});

    ecs_entity_t e_1 = ecs_new_w_pair(world, EcsIsA, base);
    ecs_entity_t e_2 = ecs_new_w_pair(world, EcsIsA, base);
    ecs_entity_t e_3 = ecs_new_w_pair(world, EcsIsA, base);

    ecs_add_id(world, e_3, Tag);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) {
        .id = ecs_id(Position),
        .src.flags = EcsUp
    });

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1), base);

    Position *ptr = ecs_field(&it, Position, 1);
    test_int(ptr->x, 10);
    test_int(ptr->y, 20);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1), base);

    test_assert(ptr == ecs_field(&it, Position, 1));

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_w_superset_childof() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_TAG(world, Tag);

    ecs_entity_t parent = ecs_set(world, 0, Position, {10, 20});
    ecs_entity_t e_1 = ecs_new_w_pair(world, EcsChildOf, parent);
    ecs_entity_t e_2 = ecs_new_w_pair(world, EcsChildOf, parent);
    ecs_entity_t e_3 = ecs_new_w_pair(world, EcsChildOf, parent);

    ecs_add_id(world, e_3, Tag);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) {
        .id = ecs_id(Position),
        .src.flags = EcsUp,
        .src.trav = EcsChildOf
    });

    {
        test_assert(ecs_term_next(&it));
        test_int(it.count, 2);
        test_int(it.entities[0], e_1);
        test_int(it.entities[1], e_2);
        test_int(ecs_field_id(&it, 1), ecs_id(Position));
        test_int(ecs_field_src(&it, 1), parent);

        Position *ptr = ecs_field(&it, Position, 1);
        test_int(ptr->x, 10);
        test_int(ptr->y, 20);
    }
    
    {
        test_assert(ecs_term_next(&it));
        test_int(it.count, 1);
        test_int(it.entities[0], e_3);
        test_int(ecs_field_id(&it, 1), ecs_id(Position));
        test_int(ecs_field_src(&it, 1), parent);

        Position *ptr = ecs_field(&it, Position, 1);
        test_int(ptr->x, 10);
        test_int(ptr->y, 20);
    }

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_w_superset_self() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_TAG(world, Tag);

    ecs_entity_t base = ecs_set(world, 0, Position, {10, 20});
    ecs_entity_t e_0 = ecs_set(world, 0, Position, {11, 22});
    ecs_entity_t e_1 = ecs_new_w_pair(world, EcsIsA, base);
    ecs_entity_t e_2 = ecs_new_w_pair(world, EcsIsA, base);
    ecs_entity_t e_3 = ecs_new_w_pair(world, EcsIsA, base);

    ecs_add_id(world, e_3, Tag);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) {
        .id = ecs_id(Position),
        .src.flags = EcsSelf|EcsUp
    });

    Position *ptr;

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], base);
    test_int(it.entities[1], e_0);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1), 0);

    ptr = ecs_field(&it, Position, 1);
    test_int(ptr[0].x, 10);
    test_int(ptr[0].y, 20);
    test_int(ptr[1].x, 11);
    test_int(ptr[1].y, 22);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1), base);

    ptr = ecs_field(&it, Position, 1);
    test_int(ptr->x, 10);
    test_int(ptr->y, 20);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1), base);

    test_assert(ptr == ecs_field(&it, Position, 1));

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_w_superset_self_childof() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_TAG(world, Tag);

    ecs_entity_t parent = ecs_set(world, 0, Position, {10, 20});
    ecs_entity_t e_0 = ecs_set(world, 0, Position, {11, 22});
    ecs_entity_t e_1 = ecs_new_w_pair(world, EcsIsA, parent);
    ecs_entity_t e_2 = ecs_new_w_pair(world, EcsIsA, parent);
    ecs_entity_t e_3 = ecs_new_w_pair(world, EcsIsA, parent);

    ecs_add_id(world, e_3, Tag);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) {
        .id = ecs_id(Position),
        .src.flags = EcsSelf|EcsUp
    });

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], parent);
    test_int(it.entities[1], e_0);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1), 0);

    Position *ptr = ecs_field(&it, Position, 1);
    test_int(ptr[0].x, 10);
    test_int(ptr[0].y, 20);
    test_int(ptr[1].x, 11);
    test_int(ptr[1].y, 22);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1), parent);

    ptr = ecs_field(&it, Position, 1);
    test_int(ptr->x, 10);
    test_int(ptr->y, 20);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1), parent);

    test_assert(ptr == ecs_field(&it, Position, 1));

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_w_superset_tag() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t base = ecs_new(world, TagA);
    ecs_entity_t e_1 = ecs_new_w_pair(world, EcsIsA, base);
    ecs_entity_t e_2 = ecs_new_w_pair(world, EcsIsA, base);
    ecs_entity_t e_3 = ecs_new_w_pair(world, EcsIsA, base);

    ecs_add_id(world, e_3, TagB);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) {
        .id = TagA,
        .src.flags = EcsUp
    });

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_src(&it, 1), base);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_src(&it, 1), base);

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_w_superset_pair() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Tgt);
    ECS_TAG(world, Tag);

    ecs_entity_t base = ecs_new_w_pair(world, Rel, Tgt);
    ecs_entity_t e_1 = ecs_new_w_pair(world, EcsIsA, base);
    ecs_entity_t e_2 = ecs_new_w_pair(world, EcsIsA, base);
    ecs_entity_t e_3 = ecs_new_w_pair(world, EcsIsA, base);

    ecs_add_id(world, e_3, Tag);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) {
        .id = ecs_pair(Rel, Tgt),
        .src.flags = EcsUp,
    });

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Tgt));
    test_int(ecs_field_src(&it, 1), base);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Tgt));
    test_int(ecs_field_src(&it, 1), base);

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_w_superset_pair_obj_wildcard() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Obj_1);
    ECS_TAG(world, Obj_2);
    ECS_TAG(world, Tag);

    ecs_entity_t base_1 = ecs_new_w_pair(world, Rel, Obj_1);
    ecs_entity_t base_2 = ecs_new_w_pair(world, Rel, Obj_2);
    ecs_entity_t e_1 = ecs_new_w_pair(world, EcsIsA, base_1);
    ecs_entity_t e_2 = ecs_new_w_pair(world, EcsIsA, base_1);
    ecs_entity_t e_3 = ecs_new_w_pair(world, EcsIsA, base_2);
    ecs_add_id(world, e_3, Tag);

    ecs_entity_t e_4 = ecs_new_w_pair(world, EcsIsA, base_2);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) {
        .id = ecs_pair(Rel, EcsWildcard),
        .src.flags = EcsUp
    });

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Obj_1));
    test_int(ecs_field_src(&it, 1), base_1);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Obj_2));
    test_int(ecs_field_src(&it, 1), base_2);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Obj_2));
    test_int(ecs_field_src(&it, 1), base_2);

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_in_stage() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);
    ECS_TAG(world, TagB);

    ecs_entity_t e1 = ecs_new(world, Tag);
    ecs_entity_t e2 = ecs_new(world, Tag);
    ecs_add(world, e2, TagB);

    ecs_readonly_begin(world);

    ecs_world_t *stage = ecs_get_stage(world, 0);
    test_assert(stage != NULL);

    ecs_iter_t it = ecs_term_iter(stage, &(ecs_term_t) { .id = Tag });
    test_assert(it.real_world == world);
    test_assert(it.world == stage);

    test_bool(ecs_term_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e1);
    test_int(it.ids[0], Tag);

    test_bool(ecs_term_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e2);
    test_int(it.ids[0], Tag);

    test_bool(ecs_term_next(&it), false);

    ecs_readonly_end(world);

    ecs_fini(world);
}

void Filter_term_iter_type_set() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_entity_t e_2 = ecs_new(world, TagA);

    ecs_add_id(world, e_2, TagB);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) {
        .id = TagA
    });

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_1);
    test_assert(it.table != NULL);
    const ecs_type_t *type = ecs_table_get_type(it.table);
    test_int(type->count, 1);
    test_int(type->array[0], TagA);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_2);
    test_assert(it.table != NULL);
    type = ecs_table_get_type(it.table);
    test_int(type->count, 2);
    test_int(type->array[0], TagA);
    test_int(type->array[1], TagB);

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_term_iter_any_match_wildcard() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Tgt);

    ecs_entity_t e1 = ecs_new_w_pair(world, Rel, Tgt);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t){ EcsAny });
    ecs_entity_t prev = 0;
    int32_t count = 0, e1_matched = 0;
    while (ecs_term_next(&it)) {
        test_assert(it.count > 0);
        test_assert(!prev || prev != it.entities[0]);
        prev = it.entities[0];
        if (it.entities[0] == e1) {
            e1_matched ++;
        }
        count ++;
    }

    test_assert(count > 0);
    test_int(e1_matched, 1);

    ecs_fini(world);
}

void Filter_term_iter_any_match_tag_and_wildcard() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Tgt);
    ECS_TAG(world, Tag);

    ecs_entity_t e1 = ecs_new_w_pair(world, Rel, Tgt);
    ecs_entity_t e2 = ecs_new(world, Tag);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t){ EcsAny });
    ecs_entity_t prev = 0;
    int32_t count = 0, e1_matched = 0, e2_matched = 0;
    while (ecs_term_next(&it)) {
        test_assert(it.count > 0);
        test_assert(!prev || prev != it.entities[0]);
        prev = it.entities[0];
        if (it.entities[0] == e1) {
            e1_matched ++;
        }
        if (it.entities[0] == e2) {
            e2_matched ++;
        }
        count ++;
    }

    test_assert(count > 0);
    test_int(e1_matched, 1);
    test_int(e2_matched, 1);

    ecs_fini(world);
}

void Filter_term_iter_any_obj() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, ObjA);
    ECS_TAG(world, ObjB);
    ECS_TAG(world, ObjC);
    ECS_TAG(world, ObjD);

    ecs_entity_t e1 = ecs_new_w_pair(world, Rel, ObjA);
    ecs_entity_t e2 = ecs_new_w_pair(world, Rel, ObjA);
    ecs_entity_t e3 = ecs_new_w_pair(world, Rel, ObjA);
    ecs_entity_t e4 = ecs_new_w_pair(world, Rel, ObjA);

    ecs_add_pair(world, e2, Rel, ObjB);
    ecs_add_pair(world, e3, Rel, ObjC);
    ecs_add_pair(world, e4, Rel, ObjC);
    ecs_add_pair(world, e4, Rel, ObjD);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t){ ecs_pair(Rel, EcsAny )});
    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e1);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e2);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e3);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e4);

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_children_iter() {
    ecs_world_t *world = ecs_mini();

    ecs_entity_t parent = ecs_new_id(world);
    ecs_entity_t child_1 = ecs_new_w_pair(world, EcsChildOf, parent);
    ecs_entity_t child_2 = ecs_new_w_pair(world, EcsChildOf, parent);

    ecs_iter_t it = ecs_children(world, parent);
    test_bool(true, ecs_children_next(&it));
    test_int(it.count, 2);
    test_uint(child_1, it.entities[0]);
    test_uint(child_2, it.entities[1]);
    test_bool(false, ecs_children_next(&it));

    ecs_fini(world);
}

void Filter_filter_iter_1_tag() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_entity_t e_3 = ecs_new(world, TagA);

    ecs_add_id(world, e_3, TagB);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_2_tags() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_entity_t e_3 = ecs_new(world, TagA);
    
    ecs_new(world, TagA); /* Non matching entity */

    ecs_add_id(world, e_1, TagB);
    ecs_add_id(world, e_2, TagB);
    ecs_add_id(world, e_3, TagB);

    ecs_add_id(world, e_3, TagC);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }, { TagB }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), TagB);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), TagB);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_2_tags_1_not() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_entity_t e_3 = ecs_new(world, TagA);

    ecs_add_id(world, e_3, TagC);
    
    ecs_entity_t e_4 = ecs_new(world, TagA); /* Non matching entity */
    ecs_add_id(world, e_4, TagB);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }, { TagB, .oper = EcsNot }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), TagB);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), TagB);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_3_tags_2_or() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, TagD);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_entity_t e_3 = ecs_new(world, TagA);

    ecs_add_id(world, e_1, TagB);
    ecs_add_id(world, e_2, TagB);
    ecs_add_id(world, e_3, TagC);
    
    ecs_entity_t e_4 = ecs_new(world, TagA); /* Non matching entity */
    ecs_add_id(world, e_4, TagD);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }, { TagB, .oper = EcsOr }, { TagC, .oper = EcsOr }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), TagB);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), TagC);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_only_optional() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    
    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "?TagA"
    }));

    ecs_entity_t e = ecs_new(world, TagA);
    int32_t count = 0;

    ecs_iter_t it = ecs_filter_iter(world, &f);
    while (ecs_filter_next(&it)) {
        if (ecs_field_is_set(&it, 1)) {
            test_assert(count == 0);
            test_int(it.count, 1);
            test_uint(it.entities[0], e);
            test_uint(TagA, ecs_field_id(&it, 1));
            count ++;
        }
    }

    test_int(count, 1);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_only_2_or() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "TagA || TagB"
    }));

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_entity_t e2 = ecs_new(world, TagA);
    ecs_add(world, e2, TagB);
    ecs_entity_t e3 = ecs_new(world, TagB);
    ecs_new(world, TagC);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(TagA, ecs_field_id(&it, 1));

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e2, it.entities[0]);
    test_uint(TagA, ecs_field_id(&it, 1));

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e3, it.entities[0]);
    test_uint(TagB, ecs_field_id(&it, 1));

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_only_3_or() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, TagD);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "TagA || TagB || TagC"
    }));

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_entity_t e2 = ecs_new(world, TagA);
    ecs_add(world, e2, TagB);
    ecs_entity_t e3 = ecs_new(world, TagB);
    ecs_entity_t e4 = ecs_new(world, TagC);
    ecs_new(world, TagD);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(TagA, ecs_field_id(&it, 1));

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e2, it.entities[0]);
    test_uint(TagA, ecs_field_id(&it, 1));

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e3, it.entities[0]);
    test_uint(TagB, ecs_field_id(&it, 1));

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e4, it.entities[0]);
    test_uint(TagC, ecs_field_id(&it, 1));

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_2_or_other_type() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "Position || Velocity"
    }));

    test_assert(f.flags & EcsFilterNoData);

    ecs_entity_t e1 = ecs_set(world, 0, Position, {10, 20});
    ecs_entity_t e2 = ecs_set(world, 0, Velocity, {10, 20});

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(ecs_id(Position), ecs_field_id(&it, 1));

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e2, it.entities[0]);
    test_uint(ecs_id(Velocity), ecs_field_id(&it, 1));
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_2_or_same_type() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_TAG(world, Rel);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "Position || (Rel, Position)"
    }));

    ecs_entity_t e1 = ecs_set(world, 0, Position, {10, 20});
    ecs_entity_t e2 = ecs_set_pair_second(world, 0, Rel, Position, {10, 20});

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(ecs_id(Position), ecs_field_id(&it, 1));
    test_uint(sizeof(Position), ecs_field_size(&it, 1));
    {
        Position *p = ecs_field(&it, Position, 1);
        test_assert(p != NULL);
        test_uint(p->x, 10);
        test_uint(p->y, 20);
    }

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e2, it.entities[0]);
    test_uint(ecs_pair(Rel, ecs_id(Position)), ecs_field_id(&it, 1));
    test_uint(sizeof(Position), ecs_field_size(&it, 1));
    {
        Position *p = ecs_field(&it, Position, 1);
        test_assert(p != NULL);
        test_uint(p->x, 10);
        test_uint(p->y, 20);
    }

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_2_or() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, Foo);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "TagA || TagB, Foo"
    }));

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_entity_t e2 = ecs_new(world, TagA);
    ecs_add(world, e2, TagB);
    ecs_entity_t e3 = ecs_new(world, TagB);

    ecs_add(world, e1, Foo);
    ecs_add(world, e2, Foo);
    ecs_add(world, e3, Foo);

    ecs_new(world, TagB);
    ecs_new(world, TagC);
    ecs_new(world, Foo);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(TagA, ecs_field_id(&it, 1));
    test_uint(Foo, ecs_field_id(&it, 2));

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e2, it.entities[0]);
    test_uint(TagA, ecs_field_id(&it, 1));
    test_uint(Foo, ecs_field_id(&it, 2));

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e3, it.entities[0]);
    test_uint(TagB, ecs_field_id(&it, 1));
    test_uint(Foo, ecs_field_id(&it, 2));

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_3_or() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, Foo);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "TagA || TagB || TagC, Foo"
    }));

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_entity_t e2 = ecs_new(world, TagA);
    ecs_add(world, e2, TagB);
    ecs_entity_t e3 = ecs_new(world, TagB);
    ecs_add(world, e3, TagC);
    ecs_entity_t e4 = ecs_new(world, TagC);

    ecs_add(world, e1, Foo);
    ecs_add(world, e2, Foo);
    ecs_add(world, e3, Foo);
    ecs_add(world, e4, Foo);

    ecs_new(world, TagB);
    ecs_new(world, TagC);
    ecs_new(world, Foo);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(TagA, ecs_field_id(&it, 1));
    test_uint(Foo, ecs_field_id(&it, 2));

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e2, it.entities[0]);
    test_uint(TagA, ecs_field_id(&it, 1));
    test_uint(Foo, ecs_field_id(&it, 2));

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e3, it.entities[0]);
    test_uint(TagB, ecs_field_id(&it, 1));
    test_uint(Foo, ecs_field_id(&it, 2));

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e4, it.entities[0]);
    test_uint(TagC, ecs_field_id(&it, 1));
    test_uint(Foo, ecs_field_id(&it, 2));

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_1_component() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_TAG(world, TagB);

    ecs_entity_t e_1 = ecs_set(world, 0, Position, {10, 21});
    ecs_entity_t e_2 = ecs_set(world, 0, Position, {12, 23});
    ecs_entity_t e_3 = ecs_set(world, 0, Position, {14, 25});

    ecs_add_id(world, e_3, TagB);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ ecs_id(Position) }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1), 0);

    Position *p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p[0].x, 10);
    test_int(p[0].y, 21);
    test_int(p[1].x, 12);
    test_int(p[1].y, 23);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1), 0);

    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p[0].x, 14);
    test_int(p[0].y, 25);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_2_components() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);
    ECS_TAG(world, TagB);

    ecs_entity_t e_1 = ecs_set(world, 0, Position, {10, 21});
    ecs_entity_t e_2 = ecs_set(world, 0, Position, {12, 23});
    ecs_entity_t e_3 = ecs_set(world, 0, Position, {14, 25});

    ecs_set(world, e_1, Velocity, {0, 1});
    ecs_set(world, e_2, Velocity, {2, 3});
    ecs_set(world, e_3, Velocity, {4, 5});

    ecs_add_id(world, e_3, TagB);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ ecs_id(Position) }, { ecs_id(Velocity) }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    {
        test_assert(ecs_filter_next(&it));
        test_int(it.count, 2);
        test_int(it.entities[0], e_1);
        test_int(it.entities[1], e_2);
        test_int(ecs_field_id(&it, 1), ecs_id(Position));
        test_int(ecs_field_src(&it, 1), 0);
        
        Position *p = ecs_field(&it, Position, 1);
        test_assert(p != NULL);
        test_int(p[0].x, 10);
        test_int(p[0].y, 21);
        test_int(p[1].x, 12);
        test_int(p[1].y, 23);

        Velocity *v = ecs_field(&it, Velocity, 2);
        test_assert(v != NULL);
        test_int(v[0].x, 0);
        test_int(v[0].y, 1);
        test_int(v[1].x, 2);
        test_int(v[1].y, 3);
    }

    {
        test_assert(ecs_filter_next(&it));
        test_int(it.count, 1);
        test_int(it.entities[0], e_3);
        test_int(ecs_field_id(&it, 1), ecs_id(Position));
        test_int(ecs_field_src(&it, 1), 0);

        Position *p = ecs_field(&it, Position, 1);
        test_assert(p != NULL);
        test_int(p[0].x, 14);
        test_int(p[0].y, 25);

        Velocity *v = ecs_field(&it, Velocity, 2);
        test_assert(v != NULL);
        test_int(v[0].x, 4);
        test_int(v[0].y, 5);
    }

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_pair_id() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Tgt);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_new_w_pair(world, Rel, Tgt);
    ecs_entity_t e_2 = ecs_new_w_pair(world, Rel, Tgt);
    ecs_entity_t e_3 = ecs_new_w_pair(world, Rel, Tgt);

    ecs_add_id(world, e_3, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ ecs_pair(Rel, EcsWildcard) }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Tgt));
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Tgt));
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_2_pair_ids() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, RelA);
    ECS_TAG(world, ObjA);
    ECS_TAG(world, RelB);
    ECS_TAG(world, ObjB);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_new_w_pair(world, RelA, ObjA);
    ecs_entity_t e_2 = ecs_new_w_pair(world, RelA, ObjA);
    ecs_entity_t e_3 = ecs_new_w_pair(world, RelA, ObjA);

    ecs_add_pair(world, e_1, RelB, ObjB);
    ecs_add_pair(world, e_2, RelB, ObjB);
    ecs_add_pair(world, e_3, RelB, ObjB);

    ecs_add_id(world, e_3, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { ecs_pair(RelA, ObjA) },
            { ecs_pair(RelB, EcsWildcard) }
        }
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(RelA, ObjA));
    test_int(ecs_field_id(&it, 2), ecs_pair(RelB, ObjB));
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(RelA, ObjA));
    test_int(ecs_field_id(&it, 2), ecs_pair(RelB, ObjB));
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_childof_pair_0_parent() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tgt);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_new_w_pair(world, EcsChildOf, Tgt);
    ecs_entity_t e_2 = ecs_new_w_pair(world, EcsChildOf, Tgt);
    ecs_entity_t e_3 = ecs_new_w_pair(world, EcsChildOf, Tgt);

    ecs_entity_t e_4 = ecs_new_w_id(world, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ ecs_pair(EcsChildOf, 0) }} /* Special for ChildOf */
    }));

    int32_t count = 0;

    ecs_iter_t it = ecs_filter_iter(world, &f);

    while (ecs_filter_next(&it)) {
        test_assert(it.count != 0);
        int i;
        for (i = 0; i < it.count; i ++) {
            test_assert(it.entities[i] != e_1);
            test_assert(it.entities[i] != e_2);
            test_assert(it.entities[i] != e_3);

            if (it.entities[i] == e_4) {
                test_assert(count == 0);
                count ++;
            }
        }
    }

    test_int(count, 1);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_pair_pred_obj() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Tgt);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_new_w_pair(world, Rel, Tgt);
    ecs_entity_t e_2 = ecs_new_w_pair(world, Rel, Tgt);
    ecs_entity_t e_3 = ecs_new_w_pair(world, Rel, Tgt);

    ecs_add_id(world, e_3, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .first.id = Rel, .second.id = EcsWildcard }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Tgt));
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Tgt));
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_pair_2_pred_obj() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, RelA);
    ECS_TAG(world, ObjA);
    ECS_TAG(world, RelB);
    ECS_TAG(world, ObjB);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_new_w_pair(world, RelA, ObjA);
    ecs_entity_t e_2 = ecs_new_w_pair(world, RelA, ObjA);
    ecs_entity_t e_3 = ecs_new_w_pair(world, RelA, ObjA);

    ecs_add_pair(world, e_1, RelB, ObjB);
    ecs_add_pair(world, e_2, RelB, ObjB);
    ecs_add_pair(world, e_3, RelB, ObjB);

    ecs_add_id(world, e_3, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .first.id = RelA, .second.id = ObjA },
            { .first.id = RelB, .second.id = EcsWildcard }
        }
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(RelA, ObjA));
    test_int(ecs_field_id(&it, 2), ecs_pair(RelB, ObjB));
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(RelA, ObjA));
    test_int(ecs_field_id(&it, 2), ecs_pair(RelB, ObjB));
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_null() {
    install_test_abort();
    ecs_world_t *world = ecs_mini();

    test_expect_abort();
    ecs_filter_iter(world, NULL);
}

void Filter_filter_iter_1_not_tag() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, Rel);
    ECS_TAG(world, Tgt);
    ECS_TAG(world, TagC);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_entity_t e_2 = ecs_new_w_pair(world, Rel, Tgt);
    ecs_entity_t e_3 = ecs_new(world, TagA);
    ecs_add_id(world, e_3, TagC);
    
    bool e_1_found = false;
    bool e_2_found = false;
    bool e_3_found = false;

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .id = TagC, .oper = EcsNot }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    while (ecs_filter_next(&it)) {
        int i;
        for (i = 0; i < it.count; i ++) {
            if (it.entities[i] == e_1) {
                test_bool(e_1_found, false);
                e_1_found = true;
            } else
            if (it.entities[i] == e_2) {
                test_bool(e_2_found, false);
                e_2_found = true;
            } else
            if (it.entities[i] == e_3) {
                e_3_found = true;
            }                        
        }
    }

    test_bool (e_1_found, true);
    test_bool (e_2_found, true);
    test_bool (e_3_found, false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_2_tags_1_optional() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_entity_t e_3 = ecs_new(world, TagA);

    ecs_add_id(world, e_3, TagB);
    
    ecs_entity_t e_4 = ecs_new(world, TagB); /* Non matching entity */
    ecs_add_id(world, e_4, TagC);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }, { TagB, .oper = EcsOptional }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), TagB);
    test_bool(ecs_field_is_set(&it, 1), true);
    test_bool(ecs_field_is_set(&it, 2), false);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), TagB);
    test_bool(ecs_field_is_set(&it, 1), true);
    test_bool(ecs_field_is_set(&it, 2), true);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_2_components_1_optional() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_COMPONENT(world, Position);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_entity_t e_3 = ecs_new(world, TagA);

    ecs_add(world, e_3, Position);

    ecs_entity_t e_4 = ecs_new(world, Position); /* Non matching entity */
    ecs_add_id(world, e_4, TagB);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }, { ecs_id(Position), .oper = EcsOptional }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), ecs_id(Position));
    test_bool(ecs_field_is_set(&it, 1), true);
    test_bool(ecs_field_is_set(&it, 2), false);
    test_int(ecs_field_src(&it, 1), 0);
    test_assert(ecs_field(&it, Position, 2) == NULL);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), ecs_id(Position));
    test_bool(ecs_field_is_set(&it, 1), true);
    test_bool(ecs_field_is_set(&it, 2), true);
    test_int(ecs_field_src(&it, 1), 0);
    test_assert(ecs_field(&it, Position, 2) != NULL);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_in_stage() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_entity_t e = ecs_new(world, Tag);

    ecs_readonly_begin(world);

    ecs_world_t *stage = ecs_get_stage(world, 0);
    test_assert(stage != NULL);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(stage, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ Tag }}
    }));

    ecs_iter_t it = ecs_filter_iter(stage, &f);
    test_assert(it.real_world == world);
    test_assert(it.world == stage);
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_int(it.ids[0], Tag);
    ecs_iter_fini(&it);

    ecs_readonly_end(world);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_type_set() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_entity_t e_2 = ecs_new(world, TagA);

    ecs_add_id(world, e_2, TagB);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_1);
    test_assert(it.table != NULL);
    const ecs_type_t *type = ecs_table_get_type(it.table);
    test_int(type->count, 1);
    test_int(type->array[0], TagA);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_2);
    test_assert(it.table != NULL);
    type = ecs_table_get_type(it.table);
    test_int(type->count, 2);
    test_int(type->array[0], TagA);
    test_int(type->array[1], TagB);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_10_tags() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, TagD);
    ECS_TAG(world, TagE);
    ECS_TAG(world, TagF);
    ECS_TAG(world, TagG);
    ECS_TAG(world, TagH);
    ECS_TAG(world, TagI);
    ECS_TAG(world, TagJ);
    ECS_TAG(world, TagK);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_add_id(world, e_1, TagB);
    ecs_add_id(world, e_1, TagC);
    ecs_add_id(world, e_1, TagD);
    ecs_add_id(world, e_1, TagE);
    ecs_add_id(world, e_1, TagF);
    ecs_add_id(world, e_1, TagG);
    ecs_add_id(world, e_1, TagH);
    ecs_add_id(world, e_1, TagI);
    ecs_add_id(world, e_1, TagJ);
    
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_add_id(world, e_2, TagB);
    ecs_add_id(world, e_2, TagC);
    ecs_add_id(world, e_2, TagD);
    ecs_add_id(world, e_2, TagE);
    ecs_add_id(world, e_2, TagF);
    ecs_add_id(world, e_2, TagG);
    ecs_add_id(world, e_2, TagH);
    ecs_add_id(world, e_2, TagI);
    ecs_add_id(world, e_2, TagJ);
    ecs_add_id(world, e_2, TagK); /* 2nd match in different table */

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {TagA}, {TagB}, {TagC}, {TagD}, {TagE}, {TagF}, {TagG}, {TagH}, 
            {TagI}, {TagJ}
        }
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_1);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), TagB);
    test_int(ecs_field_id(&it, 3), TagC);
    test_int(ecs_field_id(&it, 4), TagD);
    test_int(ecs_field_id(&it, 5), TagE);
    test_int(ecs_field_id(&it, 6), TagF);
    test_int(ecs_field_id(&it, 7), TagG);
    test_int(ecs_field_id(&it, 8), TagH);
    test_int(ecs_field_id(&it, 9), TagI);
    test_int(ecs_field_id(&it, 10), TagJ);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_2);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), TagB);
    test_int(ecs_field_id(&it, 3), TagC);
    test_int(ecs_field_id(&it, 4), TagD);
    test_int(ecs_field_id(&it, 5), TagE);
    test_int(ecs_field_id(&it, 6), TagF);
    test_int(ecs_field_id(&it, 7), TagG);
    test_int(ecs_field_id(&it, 8), TagH);
    test_int(ecs_field_id(&it, 9), TagI);
    test_int(ecs_field_id(&it, 10), TagJ);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_20_tags() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, TagD);
    ECS_TAG(world, TagE);
    ECS_TAG(world, TagF);
    ECS_TAG(world, TagG);
    ECS_TAG(world, TagH);
    ECS_TAG(world, TagI);
    ECS_TAG(world, TagJ);
    ECS_TAG(world, TagK);
    ECS_TAG(world, TagL);
    ECS_TAG(world, TagM);
    ECS_TAG(world, TagN);
    ECS_TAG(world, TagO);
    ECS_TAG(world, TagP);
    ECS_TAG(world, TagQ);
    ECS_TAG(world, TagR);
    ECS_TAG(world, TagS);
    ECS_TAG(world, TagT);
    ECS_TAG(world, TagU);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_add_id(world, e_1, TagB);
    ecs_add_id(world, e_1, TagC);
    ecs_add_id(world, e_1, TagD);
    ecs_add_id(world, e_1, TagE);
    ecs_add_id(world, e_1, TagF);
    ecs_add_id(world, e_1, TagG);
    ecs_add_id(world, e_1, TagH);
    ecs_add_id(world, e_1, TagI);
    ecs_add_id(world, e_1, TagJ);
    ecs_add_id(world, e_1, TagK);
    ecs_add_id(world, e_1, TagL);
    ecs_add_id(world, e_1, TagM);
    ecs_add_id(world, e_1, TagN);
    ecs_add_id(world, e_1, TagO);
    ecs_add_id(world, e_1, TagP);
    ecs_add_id(world, e_1, TagQ);
    ecs_add_id(world, e_1, TagR);
    ecs_add_id(world, e_1, TagS);
    ecs_add_id(world, e_1, TagT);
    
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_add_id(world, e_2, TagB);
    ecs_add_id(world, e_2, TagC);
    ecs_add_id(world, e_2, TagD);
    ecs_add_id(world, e_2, TagE);
    ecs_add_id(world, e_2, TagF);
    ecs_add_id(world, e_2, TagG);
    ecs_add_id(world, e_2, TagH);
    ecs_add_id(world, e_2, TagI);
    ecs_add_id(world, e_2, TagJ);
    ecs_add_id(world, e_2, TagK);
    ecs_add_id(world, e_2, TagL);
    ecs_add_id(world, e_2, TagM);
    ecs_add_id(world, e_2, TagN);
    ecs_add_id(world, e_2, TagO);
    ecs_add_id(world, e_2, TagP);
    ecs_add_id(world, e_2, TagQ);
    ecs_add_id(world, e_2, TagR);
    ecs_add_id(world, e_2, TagS);
    ecs_add_id(world, e_2, TagT);
    ecs_add_id(world, e_2, TagU); /* 2nd match in different table */

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms_buffer = (ecs_term_t[]){
            {TagA}, {TagB}, {TagC}, {TagD}, {TagE}, {TagF}, {TagG}, {TagH}, 
            {TagI}, {TagJ}, {TagK}, {TagL}, {TagM}, {TagN}, {TagO}, {TagP},
            {TagQ}, {TagR}, {TagS}, {TagT}
        },
        .terms_buffer_count = 20
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_1);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), TagB);
    test_int(ecs_field_id(&it, 3), TagC);
    test_int(ecs_field_id(&it, 4), TagD);
    test_int(ecs_field_id(&it, 5), TagE);
    test_int(ecs_field_id(&it, 6), TagF);
    test_int(ecs_field_id(&it, 7), TagG);
    test_int(ecs_field_id(&it, 8), TagH);
    test_int(ecs_field_id(&it, 9), TagI);
    test_int(ecs_field_id(&it, 10), TagJ);
    test_int(ecs_field_id(&it, 11), TagK);
    test_int(ecs_field_id(&it, 12), TagL);
    test_int(ecs_field_id(&it, 13), TagM);
    test_int(ecs_field_id(&it, 14), TagN);
    test_int(ecs_field_id(&it, 15), TagO);
    test_int(ecs_field_id(&it, 16), TagP);
    test_int(ecs_field_id(&it, 17), TagQ);
    test_int(ecs_field_id(&it, 18), TagR);
    test_int(ecs_field_id(&it, 19), TagS);
    test_int(ecs_field_id(&it, 20), TagT);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_2);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), TagB);
    test_int(ecs_field_id(&it, 3), TagC);
    test_int(ecs_field_id(&it, 4), TagD);
    test_int(ecs_field_id(&it, 5), TagE);
    test_int(ecs_field_id(&it, 6), TagF);
    test_int(ecs_field_id(&it, 7), TagG);
    test_int(ecs_field_id(&it, 8), TagH);
    test_int(ecs_field_id(&it, 9), TagI);
    test_int(ecs_field_id(&it, 10), TagJ);
    test_int(ecs_field_id(&it, 11), TagK);
    test_int(ecs_field_id(&it, 12), TagL);
    test_int(ecs_field_id(&it, 13), TagM);
    test_int(ecs_field_id(&it, 14), TagN);
    test_int(ecs_field_id(&it, 15), TagO);
    test_int(ecs_field_id(&it, 16), TagP);
    test_int(ecs_field_id(&it, 17), TagQ);
    test_int(ecs_field_id(&it, 18), TagR);
    test_int(ecs_field_id(&it, 19), TagS);
    test_int(ecs_field_id(&it, 20), TagT);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

typedef struct {
    float v;
} CompA, CompB, CompC, CompD, CompE, CompF, CompG, CompH, CompI, CompJ, CompK,
  CompL, CompM, CompN, CompO, CompP, CompQ, CompR, CompS, CompT, CompU;

void Filter_filter_iter_10_components() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, CompA);
    ECS_COMPONENT(world, CompB);
    ECS_COMPONENT(world, CompC);
    ECS_COMPONENT(world, CompD);
    ECS_COMPONENT(world, CompE);
    ECS_COMPONENT(world, CompF);
    ECS_COMPONENT(world, CompG);
    ECS_COMPONENT(world, CompH);
    ECS_COMPONENT(world, CompI);
    ECS_COMPONENT(world, CompJ);
    ECS_COMPONENT(world, CompK);

    ecs_entity_t e_1 = ecs_set(world, 0, CompA, {10});
    ecs_set(world, e_1, CompB, {10});
    ecs_set(world, e_1, CompC, {10});
    ecs_set(world, e_1, CompD, {10});
    ecs_set(world, e_1, CompE, {10});
    ecs_set(world, e_1, CompF, {10});
    ecs_set(world, e_1, CompG, {10});
    ecs_set(world, e_1, CompH, {10});
    ecs_set(world, e_1, CompI, {10});
    ecs_set(world, e_1, CompJ, {10});
    
    ecs_entity_t e_2 = ecs_set(world, 0, CompA, {10});
    ecs_set(world, e_2, CompB, {10});
    ecs_set(world, e_2, CompC, {10});
    ecs_set(world, e_2, CompD, {10});
    ecs_set(world, e_2, CompE, {10});
    ecs_set(world, e_2, CompF, {10});
    ecs_set(world, e_2, CompG, {10});
    ecs_set(world, e_2, CompH, {10});
    ecs_set(world, e_2, CompI, {10});
    ecs_set(world, e_2, CompJ, {10});
    ecs_set(world, e_2, CompK, {10});

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {ecs_id(CompA)}, {ecs_id(CompB)}, {ecs_id(CompC)}, {ecs_id(CompD)}, 
            {ecs_id(CompE)}, {ecs_id(CompF)}, {ecs_id(CompG)}, {ecs_id(CompH)}, 
            {ecs_id(CompI)}, {ecs_id(CompJ)}
        }
    }));

    int i;
    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_1);
    test_int(ecs_field_id(&it, 1), ecs_id(CompA));
    test_int(ecs_field_id(&it, 2), ecs_id(CompB));
    test_int(ecs_field_id(&it, 3), ecs_id(CompC));
    test_int(ecs_field_id(&it, 4), ecs_id(CompD));
    test_int(ecs_field_id(&it, 5), ecs_id(CompE));
    test_int(ecs_field_id(&it, 6), ecs_id(CompF));
    test_int(ecs_field_id(&it, 7), ecs_id(CompG));
    test_int(ecs_field_id(&it, 8), ecs_id(CompH));
    test_int(ecs_field_id(&it, 9), ecs_id(CompI));
    test_int(ecs_field_id(&it, 10), ecs_id(CompJ));

    for (i = 0; i < 10; i ++) {
        CompA *ptr = ecs_field_w_size(&it, 0, i + 1);
        test_assert(ptr != NULL);
        test_int(ptr[0].v, 10);
    }

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_2);
    test_int(ecs_field_id(&it, 1), ecs_id(CompA));
    test_int(ecs_field_id(&it, 2), ecs_id(CompB));
    test_int(ecs_field_id(&it, 3), ecs_id(CompC));
    test_int(ecs_field_id(&it, 4), ecs_id(CompD));
    test_int(ecs_field_id(&it, 5), ecs_id(CompE));
    test_int(ecs_field_id(&it, 6), ecs_id(CompF));
    test_int(ecs_field_id(&it, 7), ecs_id(CompG));
    test_int(ecs_field_id(&it, 8), ecs_id(CompH));
    test_int(ecs_field_id(&it, 9), ecs_id(CompI));
    test_int(ecs_field_id(&it, 10), ecs_id(CompJ));

    for (i = 0; i < 10; i ++) {
        CompA *ptr = ecs_field_w_size(&it, 0, i + 1);
        test_assert(ptr != NULL);
        test_int(ptr[0].v, 10);
    }

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_20_components() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, CompA);
    ECS_COMPONENT(world, CompB);
    ECS_COMPONENT(world, CompC);
    ECS_COMPONENT(world, CompD);
    ECS_COMPONENT(world, CompE);
    ECS_COMPONENT(world, CompF);
    ECS_COMPONENT(world, CompG);
    ECS_COMPONENT(world, CompH);
    ECS_COMPONENT(world, CompI);
    ECS_COMPONENT(world, CompJ);
    ECS_COMPONENT(world, CompK);
    ECS_COMPONENT(world, CompL);
    ECS_COMPONENT(world, CompM);
    ECS_COMPONENT(world, CompN);
    ECS_COMPONENT(world, CompO);
    ECS_COMPONENT(world, CompP);
    ECS_COMPONENT(world, CompQ);
    ECS_COMPONENT(world, CompR);
    ECS_COMPONENT(world, CompS);
    ECS_COMPONENT(world, CompT);
    ECS_COMPONENT(world, CompU);

    ecs_entity_t e_1 = ecs_set(world, 0, CompA, {10});
    ecs_set(world, e_1, CompB, {10});
    ecs_set(world, e_1, CompC, {10});
    ecs_set(world, e_1, CompD, {10});
    ecs_set(world, e_1, CompE, {10});
    ecs_set(world, e_1, CompF, {10});
    ecs_set(world, e_1, CompG, {10});
    ecs_set(world, e_1, CompH, {10});
    ecs_set(world, e_1, CompI, {10});
    ecs_set(world, e_1, CompJ, {10});
    ecs_set(world, e_1, CompK, {10});
    ecs_set(world, e_1, CompL, {10});
    ecs_set(world, e_1, CompM, {10});
    ecs_set(world, e_1, CompN, {10});
    ecs_set(world, e_1, CompO, {10});
    ecs_set(world, e_1, CompP, {10});
    ecs_set(world, e_1, CompQ, {10});
    ecs_set(world, e_1, CompR, {10});
    ecs_set(world, e_1, CompS, {10});
    ecs_set(world, e_1, CompT, {10});

    ecs_entity_t e_2 = ecs_set(world, 0, CompA, {10});
    ecs_set(world, e_2, CompB, {10});
    ecs_set(world, e_2, CompC, {10});
    ecs_set(world, e_2, CompD, {10});
    ecs_set(world, e_2, CompE, {10});
    ecs_set(world, e_2, CompF, {10});
    ecs_set(world, e_2, CompG, {10});
    ecs_set(world, e_2, CompH, {10});
    ecs_set(world, e_2, CompI, {10});
    ecs_set(world, e_2, CompJ, {10});
    ecs_set(world, e_2, CompK, {10});
    ecs_set(world, e_2, CompL, {10});
    ecs_set(world, e_2, CompM, {10});
    ecs_set(world, e_2, CompN, {10});
    ecs_set(world, e_2, CompO, {10});
    ecs_set(world, e_2, CompP, {10});
    ecs_set(world, e_2, CompQ, {10});
    ecs_set(world, e_2, CompR, {10});
    ecs_set(world, e_2, CompS, {10});
    ecs_set(world, e_2, CompT, {10});
    ecs_set(world, e_2, CompU, {10});

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms_buffer = (ecs_term_t[]){
            {ecs_id(CompA)}, {ecs_id(CompB)}, {ecs_id(CompC)}, {ecs_id(CompD)}, 
            {ecs_id(CompE)}, {ecs_id(CompF)}, {ecs_id(CompG)}, {ecs_id(CompH)}, 
            {ecs_id(CompI)}, {ecs_id(CompJ)}, {ecs_id(CompK)}, {ecs_id(CompL)},
            {ecs_id(CompM)}, {ecs_id(CompN)}, {ecs_id(CompO)}, {ecs_id(CompP)},
            {ecs_id(CompQ)}, {ecs_id(CompR)}, {ecs_id(CompS)}, {ecs_id(CompT)}
        },
        .terms_buffer_count = 20
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_1);
    test_int(ecs_field_id(&it, 1), ecs_id(CompA));
    test_int(ecs_field_id(&it, 2), ecs_id(CompB));
    test_int(ecs_field_id(&it, 3), ecs_id(CompC));
    test_int(ecs_field_id(&it, 4), ecs_id(CompD));
    test_int(ecs_field_id(&it, 5), ecs_id(CompE));
    test_int(ecs_field_id(&it, 6), ecs_id(CompF));
    test_int(ecs_field_id(&it, 7), ecs_id(CompG));
    test_int(ecs_field_id(&it, 8), ecs_id(CompH));
    test_int(ecs_field_id(&it, 9), ecs_id(CompI));
    test_int(ecs_field_id(&it, 10), ecs_id(CompJ));
    test_int(ecs_field_id(&it, 11), ecs_id(CompK));
    test_int(ecs_field_id(&it, 12), ecs_id(CompL));
    test_int(ecs_field_id(&it, 13), ecs_id(CompM));
    test_int(ecs_field_id(&it, 14), ecs_id(CompN));
    test_int(ecs_field_id(&it, 15), ecs_id(CompO));
    test_int(ecs_field_id(&it, 16), ecs_id(CompP));
    test_int(ecs_field_id(&it, 17), ecs_id(CompQ));
    test_int(ecs_field_id(&it, 18), ecs_id(CompR));
    test_int(ecs_field_id(&it, 19), ecs_id(CompS));
    test_int(ecs_field_id(&it, 20), ecs_id(CompT));

    int i;
    for (i = 0; i < 20; i ++) {
        CompA *ptr = ecs_field_w_size(&it, 0, i + 1);
        test_assert(ptr != NULL);
        test_int(ptr[0].v, 10);
    }

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_2);
    test_int(ecs_field_id(&it, 1), ecs_id(CompA));
    test_int(ecs_field_id(&it, 2), ecs_id(CompB));
    test_int(ecs_field_id(&it, 3), ecs_id(CompC));
    test_int(ecs_field_id(&it, 4), ecs_id(CompD));
    test_int(ecs_field_id(&it, 5), ecs_id(CompE));
    test_int(ecs_field_id(&it, 6), ecs_id(CompF));
    test_int(ecs_field_id(&it, 7), ecs_id(CompG));
    test_int(ecs_field_id(&it, 8), ecs_id(CompH));
    test_int(ecs_field_id(&it, 9), ecs_id(CompI));
    test_int(ecs_field_id(&it, 10), ecs_id(CompJ));
    test_int(ecs_field_id(&it, 11), ecs_id(CompK));
    test_int(ecs_field_id(&it, 12), ecs_id(CompL));
    test_int(ecs_field_id(&it, 13), ecs_id(CompM));
    test_int(ecs_field_id(&it, 14), ecs_id(CompN));
    test_int(ecs_field_id(&it, 15), ecs_id(CompO));
    test_int(ecs_field_id(&it, 16), ecs_id(CompP));
    test_int(ecs_field_id(&it, 17), ecs_id(CompQ));
    test_int(ecs_field_id(&it, 18), ecs_id(CompR));
    test_int(ecs_field_id(&it, 19), ecs_id(CompS));
    test_int(ecs_field_id(&it, 20), ecs_id(CompT));

    for (i = 0; i < 20; i ++) {
        CompA *ptr = ecs_field_w_size(&it, 0, i + 1);
        test_assert(ptr != NULL);
        test_int(ptr[0].v, 10);
    }

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_superset() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_entity_t base = ecs_new(world, TagA);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_new(world, TagA);

    ecs_add_pair(world, e_1, EcsIsA, base);
    ecs_add_pair(world, e_2, EcsIsA, base);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { TagA },
            { TagA, .src.flags = EcsUp }
        }
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), TagA);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_superset_childof() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_entity_t parent = ecs_new(world, TagA);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_new(world, TagA);

    ecs_add_pair(world, e_1, EcsChildOf, parent);
    ecs_add_pair(world, e_2, EcsChildOf, parent);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {TagA },
            {TagA, .src.flags = EcsUp, .src.trav = EcsChildOf}
        }
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), TagA);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_term_iter_w_readonly_term() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_entity_t e_1 = ecs_new(world, TagA);

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) { TagA, .inout = EcsIn });

    test_assert(ecs_term_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_1);
    test_int(ecs_field_id(&it, 1), TagA);
    test_bool(ecs_field_is_readonly(&it, 1), true);

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_filter_iter_w_readonly_term() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);

    ecs_entity_t e_1 = ecs_new(world, Position);
    ecs_add(world, e_1, Velocity);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ ecs_id(Position), .inout = EcsIn }, { ecs_id(Velocity) }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_1);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1), 0);
    test_bool(ecs_field_is_readonly(&it, 1), true);
    test_bool(ecs_field_is_readonly(&it, 2), false);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_w_from_nothing_term() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_add_id(world, e_1, TagB);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA, .inout = EcsIn }, { TagB, .src.flags = EcsIsEntity }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_1);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_id(&it, 2), TagB);
    test_int(ecs_field_src(&it, 1), 0);
    test_int(ecs_field_src(&it, 2), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_pair_w_rel_wildcard_n_matches() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel_1);
    ECS_TAG(world, Rel_2);
    ECS_TAG(world, Obj_1);
    ECS_TAG(world, Obj_2);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_new_w_pair(world, Rel_1, Obj_1);
    ecs_entity_t e_2 = ecs_new_w_pair(world, Rel_1, Obj_1);
    ecs_entity_t e_3 = ecs_new_w_pair(world, Rel_1, Obj_1);
    ecs_entity_t e_4 = ecs_new_w_pair(world, Rel_1, Obj_1);

    ecs_add_pair(world, e_3, Rel_1, Obj_2);
    ecs_add_pair(world, e_4, Rel_1, Obj_2);

    ecs_add_pair(world, e_3, Rel_2, Obj_1);
    ecs_add_pair(world, e_4, Rel_2, Obj_1);

    ecs_add(world, e_4, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ ecs_pair(EcsWildcard, Obj_1) }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_2, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_2, Obj_1));

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_pair_w_obj_wildcard_n_matches() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Obj_1);
    ECS_TAG(world, Obj_2);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_new_w_pair(world, Rel, Obj_1);
    ecs_entity_t e_2 = ecs_new_w_pair(world, Rel, Obj_1);
    ecs_entity_t e_3 = ecs_new_w_pair(world, Rel, Obj_1);
    ecs_entity_t e_4 = ecs_new_w_pair(world, Rel, Obj_1);

    ecs_add_pair(world, e_3, Rel, Obj_2);
    ecs_add_pair(world, e_4, Rel, Obj_2);

    ecs_add(world, e_4, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ ecs_pair(Rel, EcsWildcard) }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Obj_2));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel, Obj_2));

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_pair_w_2_wildcards_1_match() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel_1);
    ECS_TAG(world, Rel_2);
    ECS_TAG(world, Obj_1);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_new_w_pair(world, Rel_1, Obj_1);
    ecs_entity_t e_2 = ecs_new_w_pair(world, Rel_1, Obj_1);
    ecs_entity_t e_3 = ecs_new_w_pair(world, Rel_1, Obj_1);
    ecs_entity_t e_4 = ecs_new_w_pair(world, Rel_1, Obj_1);

    ecs_add_pair(world, e_1, Rel_2, Obj_1);
    ecs_add_pair(world, e_2, Rel_2, Obj_1);
    ecs_add_pair(world, e_3, Rel_2, Obj_1);
    ecs_add_pair(world, e_4, Rel_2, Obj_1);

    ecs_add(world, e_4, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { ecs_pair(Rel_1, EcsWildcard) },
            { ecs_pair(Rel_2, EcsWildcard) }
        }
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 3);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(it.entities[2], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_1));

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_pair_w_2_wildcards_2x1_matches() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel_1);
    ECS_TAG(world, Rel_2);
    ECS_TAG(world, Obj_1);
    ECS_TAG(world, Obj_2);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_new_w_pair(world, Rel_1, Obj_1);
    ecs_entity_t e_2 = ecs_new_w_pair(world, Rel_1, Obj_1);
    ecs_entity_t e_3 = ecs_new_w_pair(world, Rel_1, Obj_1);
    ecs_entity_t e_4 = ecs_new_w_pair(world, Rel_1, Obj_1);

    ecs_add_pair(world, e_3, Rel_1, Obj_2);
    ecs_add_pair(world, e_4, Rel_1, Obj_2);

    ecs_add_pair(world, e_1, Rel_2, Obj_1);
    ecs_add_pair(world, e_2, Rel_2, Obj_1);
    ecs_add_pair(world, e_3, Rel_2, Obj_1);
    ecs_add_pair(world, e_4, Rel_2, Obj_1);

    ecs_add(world, e_4, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { ecs_pair(Rel_1, EcsWildcard) },
            { ecs_pair(Rel_2, EcsWildcard) }
        }
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_2));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_2));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_1));

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_pair_w_2_wildcards_2x2_matches() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel_1);
    ECS_TAG(world, Rel_2);
    ECS_TAG(world, Obj_1);
    ECS_TAG(world, Obj_2);
    ECS_TAG(world, Tag);

    ecs_entity_t e_1 = ecs_new_w_pair(world, Rel_1, Obj_1);
    ecs_entity_t e_2 = ecs_new_w_pair(world, Rel_1, Obj_1);
    ecs_entity_t e_3 = ecs_new_w_pair(world, Rel_1, Obj_1);
    ecs_entity_t e_4 = ecs_new_w_pair(world, Rel_1, Obj_1);

    ecs_add_pair(world, e_3, Rel_1, Obj_2);
    ecs_add_pair(world, e_4, Rel_1, Obj_2);

    ecs_add_pair(world, e_1, Rel_2, Obj_1);
    ecs_add_pair(world, e_2, Rel_2, Obj_1);
    ecs_add_pair(world, e_3, Rel_2, Obj_1);
    ecs_add_pair(world, e_4, Rel_2, Obj_1);

    ecs_add_pair(world, e_1, Rel_2, Obj_2);
    ecs_add_pair(world, e_2, Rel_2, Obj_2);
    ecs_add_pair(world, e_3, Rel_2, Obj_2);
    ecs_add_pair(world, e_4, Rel_2, Obj_2);

    ecs_add(world, e_4, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { ecs_pair(Rel_1, EcsWildcard) },
            { ecs_pair(Rel_2, EcsWildcard) }
        }
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_2));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_2));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_2));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_2));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_2));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_1));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_2));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_2));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_1));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_4);
    test_int(ecs_field_id(&it, 1), ecs_pair(Rel_1, Obj_2));
    test_int(ecs_field_id(&it, 2), ecs_pair(Rel_2, Obj_2));

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_pair_w_3_wildcards_2x2x2_matches() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, X);
    ECS_TAG(world, Y);
    ECS_TAG(world, Z);

    ECS_TAG(world, A);
    ECS_TAG(world, B);
    ECS_TAG(world, C);

    ECS_ENTITY(world, E, 
        (X, A), (X, B), (Y, A), (Y, B), (Z, A), (Z, B));

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .id = ecs_pair(X, EcsWildcard) },
            { .id = ecs_pair(Y, EcsWildcard) },
            { .id = ecs_pair(Z, EcsWildcard) }
        }
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);
    char *result, *expect;

    test_bool(ecs_filter_next(&it), true);
    result = ecs_iter_str(&it); expect =
    HEAD "id:  (X,A),(Y,A),(Z,A)"
    LINE "src: 0,0,0"
    LINE "set: true,true,true"
    LINE "this:"
    LINE "    - E"
    LINE;
    test_str(result, expect);
    ecs_os_free(result);

    test_bool(ecs_filter_next(&it), true);
    result = ecs_iter_str(&it); expect =
    HEAD "id:  (X,A),(Y,A),(Z,B)"
    LINE "src: 0,0,0"
    LINE "set: true,true,true"
    LINE "this:"
    LINE "    - E"
    LINE;
    test_str(result, expect);
    ecs_os_free(result);

    test_bool(ecs_filter_next(&it), true);
    result = ecs_iter_str(&it); expect =
    HEAD "id:  (X,A),(Y,B),(Z,A)"
    LINE "src: 0,0,0"
    LINE "set: true,true,true"
    LINE "this:"
    LINE "    - E"
    LINE;
    test_str(result, expect);
    ecs_os_free(result);

    test_bool(ecs_filter_next(&it), true);
    result = ecs_iter_str(&it); expect =
    HEAD "id:  (X,A),(Y,B),(Z,B)"
    LINE "src: 0,0,0"
    LINE "set: true,true,true"
    LINE "this:"
    LINE "    - E"
    LINE;
    test_str(result, expect);
    ecs_os_free(result);

    test_bool(ecs_filter_next(&it), true);
    result = ecs_iter_str(&it); expect =
    HEAD "id:  (X,B),(Y,A),(Z,A)"
    LINE "src: 0,0,0"
    LINE "set: true,true,true"
    LINE "this:"
    LINE "    - E"
    LINE;
    test_str(result, expect);
    ecs_os_free(result);

    test_bool(ecs_filter_next(&it), true);
    result = ecs_iter_str(&it); expect =
    HEAD "id:  (X,B),(Y,A),(Z,B)"
    LINE "src: 0,0,0"
    LINE "set: true,true,true"
    LINE "this:"
    LINE "    - E"
    LINE;
    test_str(result, expect);
    ecs_os_free(result);

    test_bool(ecs_filter_next(&it), true);
    result = ecs_iter_str(&it); expect =
    HEAD "id:  (X,B),(Y,B),(Z,A)"
    LINE "src: 0,0,0"
    LINE "set: true,true,true"
    LINE "this:"
    LINE "    - E"
    LINE;
    test_str(result, expect);
    ecs_os_free(result);

    test_bool(ecs_filter_next(&it), true);
    result = ecs_iter_str(&it); expect =
    HEAD "id:  (X,B),(Y,B),(Z,B)"
    LINE "src: 0,0,0"
    LINE "set: true,true,true"
    LINE "this:"
    LINE "    - E"
    LINE;
    test_str(result, expect);
    ecs_os_free(result);

    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_pair_w_wildcard_and_nothing() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, R1);
    ECS_TAG(world, R2);
    ECS_TAG(world, O);

    ecs_entity_t e = ecs_new_id(world);
    ecs_add_pair(world, e, R1, O);
    ecs_add_pair(world, e, R2, O);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .id = ecs_pair(EcsWildcard, O) },
            { .id = ecs_pair(EcsWildcard, O), .src.flags = EcsIsEntity }
        }
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e, it.entities[0]);
    test_uint(ecs_pair(R1, O), ecs_field_id(&it, 1));
    test_uint(ecs_pair(EcsWildcard, O), ecs_field_id(&it, 2));

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e, it.entities[0]);
    test_uint(ecs_pair(R2, O), ecs_field_id(&it, 1));
    test_uint(ecs_pair(EcsWildcard, O), ecs_field_id(&it, 2));

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_any() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, TagD);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }, { EcsAny }}
    }));

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_entity_t e2 = ecs_new(world, TagA);
    ecs_entity_t e3 = ecs_new(world, TagA);
    ecs_entity_t e4 = ecs_new(world, TagA);

    ecs_add(world, e2, TagB);
    ecs_add(world, e3, TagC);
    ecs_add(world, e4, TagC);
    ecs_add(world, e4, TagD);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e2);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e3);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e4);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_wildcard_in_2nd_term() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, TgtA);
    ECS_TAG(world, TgtB);
    ECS_TAG(world, TgtC);
    ECS_TAG(world, Tag);

    ecs_entity_t e1 = ecs_new(world, Tag);
    ecs_add_pair(world, e1, Rel, TgtA);
    ecs_add_pair(world, e1, Rel, TgtB);

    ecs_entity_t e2 = ecs_new(world, Tag);
    ecs_add_pair(world, e2, Rel, TgtA);

    ecs_entity_t e3 = ecs_new(world, Tag);
    ecs_add_pair(world, e3, Rel, TgtA);
    ecs_add_pair(world, e3, Rel, TgtC);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ Tag }, { ecs_pair(Rel, EcsWildcard) }}
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e2, it.entities[0]);
    test_uint(Tag, it.ids[0]);
    test_uint(ecs_pair(Rel, TgtA), it.ids[1]);

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(Tag, it.ids[0]);
    test_uint(ecs_pair(Rel, TgtA), it.ids[1]);

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(Tag, it.ids[0]);
    test_uint(ecs_pair(Rel, TgtB), it.ids[1]);

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e3, it.entities[0]);
    test_uint(Tag, it.ids[0]);
    test_uint(ecs_pair(Rel, TgtA), it.ids[1]);

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e3, it.entities[0]);
    test_uint(Tag, it.ids[0]);
    test_uint(ecs_pair(Rel, TgtC), it.ids[1]);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_2nd_term_self_create_id_after_filter() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_filter_t *f_1 = ecs_filter(world, {
        .terms = {
            { TagA },
            { TagB, .src.flags = EcsSelf }
        }
    });

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_add(world, e1, TagB);
    ecs_new(world, TagB);

    ecs_iter_t it = ecs_filter_iter(world, f_1);
    test_bool(true, ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e1);
    test_bool(false, ecs_filter_next(&it));
    
    ecs_filter_fini(f_1);

    ecs_fini(world);
}

void Filter_filter_iter_wildcard_in_2nd_term_self() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, TgtA);
    ECS_TAG(world, TgtB);
    ECS_TAG(world, TgtC);
    ECS_TAG(world, Tag);

    ecs_entity_t e1 = ecs_new(world, Tag);
    ecs_add_pair(world, e1, Rel, TgtA);
    ecs_add_pair(world, e1, Rel, TgtB);

    ecs_entity_t e2 = ecs_new(world, Tag);
    ecs_add_pair(world, e2, Rel, TgtA);

    ecs_entity_t e3 = ecs_new(world, Tag);
    ecs_add_pair(world, e3, Rel, TgtA);
    ecs_add_pair(world, e3, Rel, TgtC);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ Tag }, { ecs_pair(Rel, EcsWildcard), .src.flags = EcsSelf }}
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e2, it.entities[0]);
    test_uint(Tag, it.ids[0]);
    test_uint(ecs_pair(Rel, TgtA), it.ids[1]);

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(Tag, it.ids[0]);
    test_uint(ecs_pair(Rel, TgtA), it.ids[1]);

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(Tag, it.ids[0]);
    test_uint(ecs_pair(Rel, TgtB), it.ids[1]);

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e3, it.entities[0]);
    test_uint(Tag, it.ids[0]);
    test_uint(ecs_pair(Rel, TgtA), it.ids[1]);

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e3, it.entities[0]);
    test_uint(Tag, it.ids[0]);
    test_uint(ecs_pair(Rel, TgtC), it.ids[1]);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_any_match_wildcard() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Tgt);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ EcsAny }}
    }));

    ecs_entity_t e1 = ecs_new_w_pair(world, Rel, Tgt);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_entity_t prev = 0;
    int32_t count = 0, e1_matched = 0;
    while (ecs_filter_next(&it)) {
        test_assert(it.count > 0);
        test_assert(!prev || prev != it.entities[0]);
        prev = it.entities[0];
        if (it.entities[0] == e1) {
            e1_matched ++;
        }
        count ++;
    }

    test_assert(count > 0);
    test_int(e1_matched, 1);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_any_match_tag_and_wildcard() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, Tgt);
    ECS_TAG(world, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ EcsAny }}
    }));

    ecs_entity_t e1 = ecs_new_w_pair(world, Rel, Tgt);
    ecs_entity_t e2 = ecs_new(world, Tag);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_entity_t prev = 0;
    int32_t count = 0, e1_matched = 0, e2_matched = 0;
    while (ecs_filter_next(&it)) {
        test_assert(it.count > 0);
        test_assert(!prev || prev != it.entities[0]);
        prev = it.entities[0];
        if (it.entities[0] == e1) {
            e1_matched ++;
        }
        if (it.entities[0] == e2) {
            e2_matched ++;
        }
        count ++;
    }

    test_assert(count > 0);
    test_int(e1_matched, 1);
    test_int(e2_matched, 1);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_any_obj() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, ObjA);
    ECS_TAG(world, ObjB);
    ECS_TAG(world, ObjC);
    ECS_TAG(world, ObjD);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .id = ecs_pair(Rel, ObjA) }, 
            { .id = ecs_pair(Rel, EcsAny) }
        }
    }));

    ecs_entity_t e1 = ecs_new_w_pair(world, Rel, ObjA);
    ecs_entity_t e2 = ecs_new_w_pair(world, Rel, ObjA);
    ecs_entity_t e3 = ecs_new_w_pair(world, Rel, ObjA);
    ecs_entity_t e4 = ecs_new_w_pair(world, Rel, ObjA);

    ecs_add_pair(world, e2, Rel, ObjB);
    ecs_add_pair(world, e3, Rel, ObjC);
    ecs_add_pair(world, e4, Rel, ObjC);
    ecs_add_pair(world, e4, Rel, ObjD);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e2);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e3);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e4);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_not_any() {
    ecs_world_t *world = ecs_mini();

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .id = EcsAny, .oper = EcsNot }}
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_not_any_obj() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, ObjA);
    ECS_TAG(world, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .id = Tag }, 
            { .id = ecs_pair(Rel, EcsAny), .oper = EcsNot }
        }
    }));

    ecs_entity_t e1 = ecs_new(world, Tag);
    ecs_entity_t e2 = ecs_new(world, Tag);

    ecs_add_pair(world, e2, Rel, ObjA);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e1);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_cascade_isa() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_entity_t base = ecs_new(world, TagA);
    ecs_entity_t inst = ecs_new_w_pair(world, EcsIsA, base);
    ecs_table_t *t1 = ecs_get_table(world, inst);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .id = TagA, .src.flags = EcsCascade }}
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], inst);
    test_assert(it.table == t1);
    test_uint(ecs_field_id(&it, 1), TagA);
    test_uint(ecs_field_size(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_cascade_childof() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_entity_t base = ecs_new(world, TagA);
    ecs_entity_t inst = ecs_new_w_pair(world, EcsChildOf, base);
    ecs_table_t *t1 = ecs_get_table(world, inst);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .id = TagA,
            .src.flags = EcsCascade,
            .src.trav = EcsChildOf
        }}
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], inst);
    test_assert(it.table == t1);
    test_uint(ecs_field_id(&it, 1), TagA);
    test_uint(ecs_field_size(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_superset_2_rel_instances() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, Rel);

    ecs_add_id(world, Rel, EcsTraversable);

    ecs_entity_t b1 = ecs_new(world, TagA);
    ecs_entity_t b2 = ecs_new(world, TagA);
    ecs_add(world, b1, TagB);
    ecs_add(world, b2, TagB);
    ecs_add(world, b1, TagC);
    ecs_add(world, b2, TagC);

    ecs_entity_t e = ecs_new_id(world);
    ecs_add_pair(world, e, Rel, b1);
    ecs_add_pair(world, e, Rel, b2);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {TagC, .src.flags = EcsUp, .src.trav = Rel }
        }
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e);
    test_uint(it.sources[0], b1);
    test_uint(it.ids[0], TagC);

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_superset_2_rel_instances_match_2nd() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, Rel);

    ecs_add_id(world, Rel, EcsTraversable);

    ecs_entity_t b1 = ecs_new(world, TagA);
    ecs_entity_t b2 = ecs_new(world, TagA);
    ecs_add(world, b1, TagB);
    ecs_add(world, b2, TagB);
    // ecs_add(world, b1, TagC);
    ecs_add(world, b2, TagC);

    ecs_entity_t e = ecs_new_id(world);
    ecs_add_pair(world, e, Rel, b1);
    ecs_add_pair(world, e, Rel, b2);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {TagC, .src.flags = EcsUp, .src.trav = Rel }
        }
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e);
    test_uint(it.sources[0], b2);
    test_uint(it.ids[0], TagC);

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_superset_2_levels() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);

    ecs_entity_t base = ecs_new_w_id(world, EcsPrefab);
    ecs_set(world, base, Position, {10, 20});

    ecs_entity_t base_2 = ecs_new_w_id(world, EcsPrefab);
    ecs_add_pair(world, base_2, EcsIsA, base);

    ecs_entity_t inst = ecs_new_w_pair(world, EcsIsA, base_2);

    ecs_filter_t *f = ecs_filter(world, {
        .terms[0] = { .id = ecs_id(Position) }
    });

    ecs_iter_t it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(inst, it.entities[0]);
    test_uint(base, it.sources[0]);
    test_uint(ecs_id(Position), ecs_field_id(&it, 1));
    Position *p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_filter_iter_superset_only_w_owned() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, R, EcsTraversable);
    ECS_COMPONENT(world, Position);

    ecs_entity_t e_0 = ecs_set(world, 0, Position, {10, 20});
    ecs_entity_t e_1 = ecs_set(world, 0, Position, {30, 40});
    ecs_entity_t e_2 = ecs_set(world, 0, Position, {50, 60});
    ecs_entity_t e_3 = ecs_set(world, 0, Position, {70, 80});

    ecs_add_pair(world, e_3, R, e_2);
    ecs_add_pair(world, e_2, R, e_1);
    ecs_add_pair(world, e_1, R, e_0);

    ecs_filter_t *f = ecs_filter(world, {
        .expr = "Position(up(R))"
    });

    ecs_iter_t it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e_3);
    test_uint(it.sources[0], e_2);
    Position *p = ecs_field(&it, Position, 1);
    test_int(p[0].x, 50);
    test_int(p[0].y, 60);

    test_bool(true, ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e_2);
    test_uint(it.sources[0], e_1);
    p = ecs_field(&it, Position, 1);
    test_int(p[0].x, 30);
    test_int(p[0].y, 40);

    test_bool(true, ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e_1);
    test_uint(it.sources[0], e_0);
    p = ecs_field(&it, Position, 1);
    test_int(p[0].x, 10);
    test_int(p[0].y, 20);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_filter_iter_superset_after_add() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);

    ecs_entity_t base = ecs_new_w_id(world, EcsPrefab);
    ecs_set(world, base, Position, {10, 20});

    ecs_entity_t base_2 = ecs_new_w_id(world, EcsPrefab);
    ecs_add_pair(world, base_2, EcsIsA, base);
    
    ecs_entity_t inst = ecs_new_w_pair(world, EcsIsA, base_2);

    ecs_filter_t *f = ecs_filter(world, {
        .terms[0] = { .id = ecs_id(Position) }
    });

    ecs_iter_t it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(inst, it.entities[0]);
    test_uint(base, it.sources[0]);
    test_uint(ecs_id(Position), ecs_field_id(&it, 1));
    Position *p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);
    test_bool(false, ecs_filter_next(&it));

    ecs_set(world, base_2, Position, {20, 30});

    it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(inst, it.entities[0]);
    test_uint(base_2, it.sources[0]);
    test_uint(ecs_id(Position), ecs_field_id(&it, 1));
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 20);
    test_int(p->y, 30);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_filter_iter_superset_after_remove() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);

    ecs_entity_t base = ecs_new_w_id(world, EcsPrefab);
    ecs_set(world, base, Position, {10, 20});

    ecs_entity_t base_2 = ecs_new_w_id(world, EcsPrefab);
    ecs_add_pair(world, base_2, EcsIsA, base);
    ecs_set(world, base_2, Position, {20, 30});

    ecs_entity_t inst = ecs_new_w_pair(world, EcsIsA, base_2);

    ecs_filter_t *f = ecs_filter(world, {
        .terms[0] = { .id = ecs_id(Position) }
    });

    ecs_iter_t it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(inst, it.entities[0]);
    test_uint(base_2, it.sources[0]);
    test_uint(ecs_id(Position), ecs_field_id(&it, 1));
    Position *p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 20);
    test_int(p->y, 30);
    test_bool(false, ecs_filter_next(&it));

    ecs_remove(world, base_2, Position);

    it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(inst, it.entities[0]);
    test_uint(base, it.sources[0]);
    test_uint(ecs_id(Position), ecs_field_id(&it, 1));
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_filter_iter_superset_after_clear() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);

    ecs_entity_t base = ecs_new_w_id(world, EcsPrefab);
    ecs_set(world, base, Position, {10, 20});

    ecs_entity_t base_2 = ecs_new_w_id(world, EcsPrefab);
    ecs_add_pair(world, base_2, EcsIsA, base);
    ecs_set(world, base_2, Position, {20, 30});

    ecs_entity_t base_3 = ecs_new_w_id(world, EcsPrefab);
    ecs_add_pair(world, base_3, EcsIsA, base);
    ecs_set(world, base_3, Position, {40, 50});

    ecs_entity_t inst = ecs_new_w_pair(world, EcsIsA, base_2);
    ecs_add_pair(world, inst, EcsIsA, base_3);

    ecs_filter_t *f = ecs_filter(world, {
        .terms[0] = { .id = ecs_id(Position) }
    });

    ecs_iter_t it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(inst, it.entities[0]);
    test_uint(base_2, it.sources[0]);
    test_uint(ecs_id(Position), ecs_field_id(&it, 1));
    Position *p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 20);
    test_int(p->y, 30);
    test_bool(false, ecs_filter_next(&it));

    ecs_clear(world, base_2);

    it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(inst, it.entities[0]);
    test_uint(base_3, it.sources[0]);
    test_uint(ecs_id(Position), ecs_field_id(&it, 1));
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 40);
    test_int(p->y, 50);
    test_bool(false, ecs_filter_next(&it));

    ecs_clear(world, base_3);

    it = ecs_filter_iter(world, f);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_filter_iter_superset_after_delete() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);

    ecs_entity_t base = ecs_new_w_id(world, EcsPrefab);
    ecs_set(world, base, Position, {10, 20});

    ecs_entity_t base_2 = ecs_new_w_id(world, EcsPrefab);
    ecs_add_pair(world, base_2, EcsIsA, base);
    ecs_set(world, base_2, Position, {20, 30});

    ecs_entity_t base_3 = ecs_new_w_id(world, EcsPrefab);
    ecs_add_pair(world, base_3, EcsIsA, base);
    ecs_set(world, base_3, Position, {40, 50});

    ecs_entity_t inst = ecs_new_w_pair(world, EcsIsA, base_2);
    ecs_add_pair(world, inst, EcsIsA, base_3);

    ecs_filter_t *f = ecs_filter(world, {
        .terms[0] = { .id = ecs_id(Position) }
    });

    ecs_iter_t it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(inst, it.entities[0]);
    test_uint(base_2, it.sources[0]);
    test_uint(ecs_id(Position), ecs_field_id(&it, 1));
    Position *p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 20);
    test_int(p->y, 30);
    test_bool(false, ecs_filter_next(&it));

    ecs_delete(world, base_2);

    it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(inst, it.entities[0]);
    test_uint(base_3, it.sources[0]);
    test_uint(ecs_id(Position), ecs_field_id(&it, 1));
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 40);
    test_int(p->y, 50);
    test_bool(false, ecs_filter_next(&it));

    ecs_delete(world, base_3);

    it = ecs_filter_iter(world, f);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_filter_iter_2_terms_superset_2_rel_instances() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, Rel);

    ecs_add_id(world, Rel, EcsTraversable);

    ecs_entity_t b1 = ecs_new(world, TagA);
    ecs_entity_t b2 = ecs_new(world, TagA);
    ecs_add(world, b1, TagB);
    ecs_add(world, b2, TagB);
    ecs_add(world, b1, TagC);
    ecs_add(world, b2, TagC);

    ecs_entity_t e = ecs_new_id(world);
    ecs_add(world, e, TagA);
    ecs_add_pair(world, e, Rel, b1);
    ecs_add_pair(world, e, Rel, b2);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {TagA},
            {TagC, .src.flags = EcsUp, .src.trav = Rel }
        }
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e);
    test_uint(it.sources[0], 0);
    test_uint(it.sources[1], b1);
    test_uint(it.ids[0], TagA);
    test_uint(it.ids[1], TagC);

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_2_terms_superset_2_rel_instances_match_2nd() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, Rel);

    ecs_add_id(world, Rel, EcsTraversable);

    ecs_entity_t b1 = ecs_new(world, TagA);
    ecs_entity_t b2 = ecs_new(world, TagA);
    ecs_add(world, b1, TagB);
    ecs_add(world, b2, TagB);
    // ecs_add(world, b1, TagC);
    ecs_add(world, b2, TagC);

    ecs_entity_t e = ecs_new_id(world);
    ecs_add(world, e, TagA);
    ecs_add_pair(world, e, Rel, b1);
    ecs_add_pair(world, e, Rel, b2);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            {TagA},
            {TagC, .src.flags = EcsUp, .src.trav = Rel }
        }
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e);
    test_uint(it.sources[0], 0);
    test_uint(it.sources[1], b2);
    test_uint(it.ids[0], TagA);
    test_uint(it.ids[1], TagC);

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_superset_parent_w_isa() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);

    ecs_entity_t base_1 = ecs_set(world, 0, Position, {10, 20});
    ecs_entity_t base = ecs_new_w_pair(world, EcsIsA, base_1);
    ecs_entity_t inst = ecs_new_w_pair(world, EcsChildOf, base);

    ecs_filter_t *f = ecs_filter(world, {
        .terms[0] = { .id = ecs_id(Position), .src = {
            .flags = EcsParent
        }}
    });

    test_assert(f != NULL);

    ecs_iter_t it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(inst, it.entities[0]);
    test_uint(base_1, it.sources[0]);
    test_uint(ecs_id(Position), ecs_field_id(&it, 1));
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_filter_iter_superset_isa_after_remove_parent() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);

    ecs_filter_t *f = ecs_filter(world, {
        .terms = {{ ecs_id(Position), .src.flags = EcsUp, .inout = EcsIn }}
    });

    ecs_entity_t base = ecs_new_prefab(world, "Base");
    ecs_set(world, base, Position, {10, 20});

    ecs_entity_t parent0 = ecs_new(world, 0);
    ecs_entity_t parent1 = ecs_new(world, 0);
    ecs_entity_t child0 = ecs_new_w_pair(world, EcsChildOf, parent0);
    ecs_entity_t child1 = ecs_new_w_pair(world, EcsChildOf, parent1);
    ecs_add_pair(world, child0, EcsIsA, base);
    ecs_add_pair(world, child1, EcsIsA, base);

    ecs_iter_t it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_uint(1, it.count);
    test_uint(child0, it.entities[0]);
    Position *p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p[0].x, 10);
    test_int(p[0].y, 20);

    test_bool(true, ecs_filter_next(&it));
    test_uint(1, it.count);
    test_uint(child1, it.entities[0]);
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p[0].x, 10);
    test_int(p[0].y, 20);
    test_bool(false, ecs_filter_next(&it));

    ecs_delete(world, parent1);

    it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_uint(1, it.count);
    test_uint(child0, it.entities[0]);
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p[0].x, 10);
    test_int(p[0].y, 20);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_filter_iter_superset_isa_create_table_after_iter() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);

    ecs_entity_t tag = ecs_new_id(world);
    ecs_entity_t base = ecs_new_id(world);
    ecs_add_id(world, base, EcsPrefab);
    ecs_set(world, base, Position, {10, 20});
    ecs_entity_t inst_1 = ecs_new_w_pair(world, EcsIsA, base);

    ecs_filter_t *f = ecs_filter(world, {
        .terms = {{ ecs_id(Position), .src.flags = EcsUp }}
    });

    ecs_iter_t it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(inst_1, it.entities[0]);
    test_uint(base, it.sources[0]);
    test_uint(ecs_id(Position), ecs_field_id(&it, 1));
    Position *p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);
    test_bool(false, ecs_filter_next(&it));

    ecs_entity_t inst_2 = ecs_new_w_pair(world, EcsIsA, base);
    ecs_add_id(world, inst_2, tag);

    it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(inst_1, it.entities[0]);
    test_uint(base, it.sources[0]);
    test_uint(ecs_id(Position), ecs_field_id(&it, 1));
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(inst_2, it.entities[0]);
    test_uint(base, it.sources[0]);
    test_uint(ecs_id(Position), ecs_field_id(&it, 1));
    p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_filter_iter_superset_2_relations() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_filter_t *f = ecs_filter(world, {
        .terms = {
            { .id = TagA, .src.trav = EcsChildOf, .src.flags = EcsUp },
            { .id = TagA, .src.trav = EcsIsA, .src.flags = EcsUp },
        }
    });

    ecs_entity_t base = ecs_new(world, TagA);
    ecs_entity_t parent = ecs_new(world, TagA);

    ecs_entity_t e1 = ecs_new_id(world);
    ecs_add_pair(world, e1, EcsIsA, base);
    ecs_add_pair(world, e1, EcsChildOf, parent);

    ecs_entity_t e2 = ecs_new_id(world);
    ecs_add_pair(world, e2, EcsIsA, base);
    ecs_add_pair(world, e2, EcsChildOf, parent);

    ecs_iter_t it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(2, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(e2, it.entities[1]);
    test_uint(parent, it.sources[0]);
    test_uint(base, it.sources[1]);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_filter_iter_superset_2_relations_instanced() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_filter_t *f = ecs_filter(world, {
        .terms = {
            { .id = TagA, .src.trav = EcsChildOf, .src.flags = EcsUp },
            { .id = TagA, .src.trav = EcsIsA, .src.flags = EcsUp },
        },
        .instanced = true
    });

    ecs_entity_t base = ecs_new(world, TagA);
    ecs_entity_t parent = ecs_new(world, TagA);

    ecs_entity_t e1 = ecs_new_id(world);
    ecs_add_pair(world, e1, EcsIsA, base);
    ecs_add_pair(world, e1, EcsChildOf, parent);

    ecs_entity_t e2 = ecs_new_id(world);
    ecs_add_pair(world, e2, EcsIsA, base);
    ecs_add_pair(world, e2, EcsChildOf, parent);

    ecs_iter_t it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(2, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(e2, it.entities[1]);
    test_uint(parent, it.sources[0]);
    test_uint(base, it.sources[1]);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_filter_iter_superset_2_relations_w_component() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);

    ecs_filter_t *f = ecs_filter(world, {
        .terms = {
            { .id = ecs_id(Position), .src.trav = EcsChildOf, .src.flags = EcsUp },
            { .id = ecs_id(Position), .src.trav = EcsIsA, .src.flags = EcsUp },
        }
    });

    ecs_entity_t base = ecs_set(world, 0, Position, {10, 20});
    ecs_entity_t parent = ecs_set(world, 0, Position, {30, 40});

    ecs_entity_t e1 = ecs_new_id(world);
    ecs_add_pair(world, e1, EcsIsA, base);
    ecs_add_pair(world, e1, EcsChildOf, parent);

    ecs_entity_t e2 = ecs_new_id(world);
    ecs_add_pair(world, e2, EcsIsA, base);
    ecs_add_pair(world, e2, EcsChildOf, parent);

    ecs_iter_t it = ecs_filter_iter(world, f);
    {
        test_bool(true, ecs_filter_next(&it));
        test_int(1, it.count);
        test_uint(e1, it.entities[0]);
        test_uint(parent, it.sources[0]);
        test_uint(base, it.sources[1]);
        Position *p1 = ecs_field(&it, Position, 1);
        Position *p2 = ecs_field(&it, Position, 2);
        test_assert(p1 != NULL);
        test_assert(p2 != NULL);
        test_int(p1->x, 30);
        test_int(p1->y, 40);
        test_int(p2->x, 10);
        test_int(p2->y, 20);
    }
    {
        test_bool(true, ecs_filter_next(&it));
        test_int(1, it.count);
        test_uint(e2, it.entities[0]);
        test_uint(parent, it.sources[0]);
        test_uint(base, it.sources[1]);
        Position *p1 = ecs_field(&it, Position, 1);
        Position *p2 = ecs_field(&it, Position, 2);
        test_assert(p1 != NULL);
        test_assert(p2 != NULL);
        test_int(p1->x, 30);
        test_int(p1->y, 40);
        test_int(p2->x, 10);
        test_int(p2->y, 20);
    }
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_filter_iter_superset_2_relations_instanced_w_component() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);

    ecs_filter_t *f = ecs_filter(world, {
        .terms = {
            { .id = ecs_id(Position), .src.trav = EcsChildOf, .src.flags = EcsUp },
            { .id = ecs_id(Position), .src.trav = EcsIsA, .src.flags = EcsUp },
        },
        .instanced = true
    });

    ecs_entity_t base = ecs_set(world, 0, Position, {10, 20});
    ecs_entity_t parent = ecs_set(world, 0, Position, {30, 40});

    ecs_entity_t e1 = ecs_new_id(world);
    ecs_add_pair(world, e1, EcsIsA, base);
    ecs_add_pair(world, e1, EcsChildOf, parent);

    ecs_entity_t e2 = ecs_new_id(world);
    ecs_add_pair(world, e2, EcsIsA, base);
    ecs_add_pair(world, e2, EcsChildOf, parent);

    ecs_iter_t it = ecs_filter_iter(world, f);
    {
        test_bool(true, ecs_filter_next(&it));
        test_int(2, it.count);
        test_uint(e1, it.entities[0]);
        test_uint(e2, it.entities[1]);
        test_uint(parent, it.sources[0]);
        test_uint(base, it.sources[1]);
        Position *p1 = ecs_field(&it, Position, 1);
        Position *p2 = ecs_field(&it, Position, 2);
        test_assert(p1 != NULL);
        test_assert(p2 != NULL);
        test_int(p1->x, 30);
        test_int(p1->y, 40);
        test_int(p2->x, 10);
        test_int(p2->y, 20);
    }
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_filter_iter_not_up_disabled() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_filter_t *f = ecs_filter(world, {
        .terms = {
            { TagA },
            { .id = EcsDisabled, .src.flags = EcsUp, .src.trav = EcsChildOf, .oper = EcsNot }
        }
    });
    test_assert(f != NULL);

    ecs_entity_t parent = ecs_new_w_id(world, EcsDisabled);

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_entity_t e2 = ecs_new(world, TagA);
    ecs_add_id(world, e2, EcsDisabled);
    ecs_entity_t e3 = ecs_new(world, TagA);
    ecs_add_pair(world, e3, EcsChildOf, parent);
    
    ecs_iter_t it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(TagA, it.ids[0]);
    test_uint(0, it.sources[0]);

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);
    
    ecs_fini(world);
}

void Filter_filter_iter_pair_wildcard_component() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Mass);

    ecs_filter_t *f = ecs_filter(world, {
        .terms = {
            { .id = ecs_pair(EcsWildcard, ecs_id(Position)) },
        }
    });
    test_assert(f != NULL);

    ecs_entity_t e1 = ecs_new_id(world);
    ecs_add_pair(world, e1, ecs_id(Mass), ecs_id(Position));

    ecs_iter_t it = ecs_filter_iter(world, f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(0, it.sizes[0]);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);
    
    ecs_fini(world);
}

void Filter_filter_w_10_terms() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, TagD);
    ECS_TAG(world, TagE);
    ECS_TAG(world, TagF);
    ECS_TAG(world, TagG);
    ECS_TAG(world, TagH);
    ECS_TAG(world, TagI);
    ECS_TAG(world, TagJ);

    ecs_filter_t f_1 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_1,
        .terms = {
            {TagA}, {TagB}, {TagC}, {TagD}, {TagE}, {TagF}, {TagG}, {TagH}, 
            {TagI}, {TagJ}
        }
    }));

    test_int(f_1.term_count, 10);
    test_assert(f_1.terms != NULL);
    test_int(f_1.terms[0].id, TagA);
    test_int(f_1.terms[1].id, TagB);
    test_int(f_1.terms[2].id, TagC);
    test_int(f_1.terms[3].id, TagD);
    test_int(f_1.terms[4].id, TagE);
    test_int(f_1.terms[5].id, TagF);
    test_int(f_1.terms[6].id, TagG);
    test_int(f_1.terms[7].id, TagH);
    test_int(f_1.terms[8].id, TagI);
    test_int(f_1.terms[9].id, TagJ);

    ecs_entity_t e = ecs_new_id(world);
    ecs_add(world, e, TagA);
    ecs_add(world, e, TagB);
    ecs_add(world, e, TagC);
    ecs_add(world, e, TagD);
    ecs_add(world, e, TagE);
    ecs_add(world, e, TagF);
    ecs_add(world, e, TagG);
    ecs_add(world, e, TagH);
    ecs_add(world, e, TagI);
    ecs_add(world, e, TagJ);

    ecs_iter_t it = ecs_filter_iter(world, &f_1);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_int(it.ids[0], TagA);
    test_int(it.ids[1], TagB);
    test_int(it.ids[2], TagC);
    test_int(it.ids[3], TagD);
    test_int(it.ids[4], TagE);
    test_int(it.ids[5], TagF);
    test_int(it.ids[6], TagG);
    test_int(it.ids[7], TagH);
    test_int(it.ids[8], TagI);
    test_int(it.ids[9], TagJ);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f_1);

    ecs_fini(world);
}

void Filter_filter_w_10_terms_move() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, TagD);
    ECS_TAG(world, TagE);
    ECS_TAG(world, TagF);
    ECS_TAG(world, TagG);
    ECS_TAG(world, TagH);
    ECS_TAG(world, TagI);
    ECS_TAG(world, TagJ);

    ecs_filter_t f_1 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_1,
        .terms = {
            {TagA}, {TagB}, {TagC}, {TagD}, {TagE}, {TagF}, {TagG}, {TagH}, 
            {TagI}, {TagJ}
        }
    }));

    test_int(f_1.term_count, 10);
    test_assert(f_1.terms != NULL);
    test_int(f_1.terms[0].id, TagA);
    test_int(f_1.terms[1].id, TagB);
    test_int(f_1.terms[2].id, TagC);
    test_int(f_1.terms[3].id, TagD);
    test_int(f_1.terms[4].id, TagE);
    test_int(f_1.terms[5].id, TagF);
    test_int(f_1.terms[6].id, TagG);
    test_int(f_1.terms[7].id, TagH);
    test_int(f_1.terms[8].id, TagI);
    test_int(f_1.terms[9].id, TagJ);

    ecs_filter_t f_2 = {0};
    ecs_filter_move(&f_2, &f_1);    

    test_int(f_2.term_count, 10);
    test_assert(f_2.terms != NULL);
    test_int(f_2.terms[0].id, TagA);
    test_int(f_2.terms[1].id, TagB);
    test_int(f_2.terms[2].id, TagC);
    test_int(f_2.terms[3].id, TagD);
    test_int(f_2.terms[4].id, TagE);
    test_int(f_2.terms[5].id, TagF);
    test_int(f_2.terms[6].id, TagG);
    test_int(f_2.terms[7].id, TagH);
    test_int(f_2.terms[8].id, TagI);
    test_int(f_2.terms[9].id, TagJ);

    test_int(f_1.term_count, 0);
    test_assert(f_1.terms == NULL); 

    ecs_filter_fini(&f_1);
    ecs_filter_fini(&f_2);

    ecs_fini(world);
}

void Filter_filter_w_10_terms_copy() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, TagD);
    ECS_TAG(world, TagE);
    ECS_TAG(world, TagF);
    ECS_TAG(world, TagG);
    ECS_TAG(world, TagH);
    ECS_TAG(world, TagI);
    ECS_TAG(world, TagJ);

    ecs_filter_t f_1 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_1,
        .terms = {
            {TagA}, {TagB}, {TagC}, {TagD}, {TagE}, {TagF}, {TagG}, {TagH}, 
            {TagI}, {TagJ}
        }
    }));

    test_int(f_1.term_count, 10);
    test_assert(f_1.terms != NULL);
    test_int(f_1.terms[0].id, TagA);
    test_int(f_1.terms[1].id, TagB);
    test_int(f_1.terms[2].id, TagC);
    test_int(f_1.terms[3].id, TagD);
    test_int(f_1.terms[4].id, TagE);
    test_int(f_1.terms[5].id, TagF);
    test_int(f_1.terms[6].id, TagG);
    test_int(f_1.terms[7].id, TagH);
    test_int(f_1.terms[8].id, TagI);
    test_int(f_1.terms[9].id, TagJ);

    ecs_filter_t f_2 = {0};
    ecs_filter_copy(&f_2, &f_1);    

    test_int(f_1.term_count, 10);
    test_assert(f_1.terms != NULL);
    test_int(f_1.terms[0].id, TagA);
    test_int(f_1.terms[1].id, TagB);
    test_int(f_1.terms[2].id, TagC);
    test_int(f_1.terms[3].id, TagD);
    test_int(f_1.terms[4].id, TagE);
    test_int(f_1.terms[5].id, TagF);
    test_int(f_1.terms[6].id, TagG);
    test_int(f_1.terms[7].id, TagH);
    test_int(f_1.terms[8].id, TagI);
    test_int(f_1.terms[9].id, TagJ);

    test_int(f_2.term_count, 10);
    test_assert(f_2.terms != NULL);
    test_int(f_2.terms[0].id, TagA);
    test_int(f_2.terms[1].id, TagB);
    test_int(f_2.terms[2].id, TagC);
    test_int(f_2.terms[3].id, TagD);
    test_int(f_2.terms[4].id, TagE);
    test_int(f_2.terms[5].id, TagF);
    test_int(f_2.terms[6].id, TagG);
    test_int(f_2.terms[7].id, TagH);
    test_int(f_2.terms[8].id, TagI);
    test_int(f_2.terms[9].id, TagJ);

    test_assert(f_1.terms != f_2.terms); 

    ecs_filter_fini(&f_1);
    ecs_filter_fini(&f_2);

    ecs_fini(world);
}

void Filter_match_disabled() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_add_id(world, e_2, EcsDisabled);
    ecs_entity_t e_3 = ecs_new(world, TagA);
    ecs_add_id(world, e_3, EcsPrefab);

    ecs_filter_t f_1 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){ 
        .storage = &f_1,
        .terms = {{ TagA }}
    }));

    ecs_filter_t f_2 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){ 
        .storage = &f_2,
        .terms = {{ TagA }, { EcsDisabled, .oper = EcsOptional }}
    }));

    test_bool(f_1.flags & EcsFilterMatchDisabled, false);
    test_bool(f_2.flags & EcsFilterMatchDisabled, true);

    ecs_iter_t it = ecs_filter_iter(world, &f_1);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_1);
    test_int(ecs_field_id(&it, 1), TagA);
    test_assert(!ecs_filter_next(&it));

    it = ecs_filter_iter(world, &f_2);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_1);
    test_int(ecs_field_id(&it, 1), TagA);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_2);
    test_int(ecs_field_id(&it, 1), TagA);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f_1);
    ecs_filter_fini(&f_2);

    ecs_fini(world);
}

void Filter_match_prefab() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_add_id(world, e_2, EcsDisabled);
    ecs_entity_t e_3 = ecs_new(world, TagA);
    ecs_add_id(world, e_3, EcsPrefab);

    ecs_filter_t f_1 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){ 
        .storage = &f_1,
        .terms = {{ TagA }}
    }));

    ecs_filter_t f_2 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){ 
        .storage = &f_2,
        .terms = {{ TagA }, { EcsPrefab, .oper = EcsOptional }}
    }));

    test_bool(f_1.flags & EcsFilterMatchPrefab, false);
    test_bool(f_2.flags & EcsFilterMatchPrefab, true);

    ecs_iter_t it = ecs_filter_iter(world, &f_1);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_1);
    test_int(ecs_field_id(&it, 1), TagA);
    test_assert(!ecs_filter_next(&it));

    it = ecs_filter_iter(world, &f_2);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_1);
    test_int(ecs_field_id(&it, 1), TagA);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_3);
    test_int(ecs_field_id(&it, 1), TagA);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f_1);
    ecs_filter_fini(&f_2);

    ecs_fini(world);
}

void Filter_chain_term_iter() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_add_id(world, e_1, TagB);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_add_id(world, e_2, TagB);

    ecs_new(world, TagA); /* Matches filter 1, not filter 2 */

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagB }}
    }));

    ecs_iter_t child_it = ecs_term_iter(world, &(ecs_term_t) { TagA });
    ecs_iter_t it = ecs_filter_chain_iter(&child_it, &f);
    test_int(it.field_count, 1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), TagB);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_chain_filter_iter() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_add_id(world, e_1, TagB);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_add_id(world, e_2, TagB);

    ecs_new(world, TagA); /* Matches filter 1, not filter 2 */

    ecs_filter_t f_1 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_1,
        .terms = {{ TagA }}
    }));

    ecs_filter_t f_2 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_2,
        .terms = {{ TagB }}
    }));

    ecs_iter_t child_it = ecs_filter_iter(world, &f_1);
    ecs_iter_t it = ecs_filter_chain_iter(&child_it, &f_2);
    test_int(it.field_count, 1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), TagB);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f_1);
    ecs_filter_fini(&f_2);

    ecs_fini(world);
}

void Filter_chain_query_iter() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_add_id(world, e_1, TagB);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_add_id(world, e_2, TagB);

    ecs_new(world, TagA); /* Matches filter 1, not filter 2 */

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagB }}
    }));

    ecs_query_t *q = ecs_query_init(world, &(ecs_query_desc_t){
        .filter.terms = {{ TagA }}
    });
    test_assert(q != NULL);

    ecs_iter_t child_it = ecs_query_iter(world, q);
    ecs_iter_t it = ecs_filter_chain_iter(&child_it, &f);
    test_int(it.field_count, 1);
    
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), TagB);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_query_fini(q);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_chain_rule_iter() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_add_id(world, e_1, TagB);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_add_id(world, e_2, TagB);

    ecs_new(world, TagA); /* Matches filter 1, not filter 2 */

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagB }}
    }));

    ecs_rule_t *r = ecs_rule_init(world, &(ecs_filter_desc_t){
        .terms = {{ TagB }}
    });

    test_assert(r != NULL);

    ecs_iter_t child_it = ecs_rule_iter(world, r);
    ecs_iter_t it = ecs_filter_chain_iter(&child_it, &f);
    test_int(it.field_count, 1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), TagB);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_rule_fini(r);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_chain_iter_2_levels() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_add_id(world, e_1, TagB);
    ecs_add_id(world, e_1, TagC);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_add_id(world, e_2, TagB);
    ecs_add_id(world, e_2, TagC);

    ecs_entity_t e_3 = ecs_new(world, TagA);
    ecs_add_id(world, e_3, TagB);

    ecs_new(world, TagA);

    ecs_filter_t f_2 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_2,
        .terms = {{ TagB }}
    }));

    ecs_filter_t f_3 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_3,
        .terms = {{ TagC }}
    }));

    ecs_iter_t it_a = ecs_term_iter(world, &(ecs_term_t) { TagA });
    ecs_iter_t it_b = ecs_filter_chain_iter(&it_a, &f_2);
    ecs_iter_t it = ecs_filter_chain_iter(&it_b, &f_3);
    test_int(it.field_count, 1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it_a, 1), TagA);
    test_int(ecs_field_id(&it_b, 1), TagB);
    test_int(ecs_field_id(&it, 1), TagC);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f_2);
    ecs_filter_fini(&f_3);

    ecs_fini(world);
}

void Filter_chain_term_iter_w_term_iter() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_add_id(world, e_1, TagB);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_add_id(world, e_2, TagB);

    ecs_new(world, TagA); /* Matches filter 1, not filter 2 */

    ecs_iter_t child_it = ecs_term_iter(world, &(ecs_term_t) { TagA });
    ecs_iter_t it = ecs_term_chain_iter(&child_it, &(ecs_term_t) { TagB });
    test_int(it.field_count, 1);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), TagB);
    test_int(ecs_field_src(&it, 1), 0);
    test_assert(it.table != NULL);
    test_assert(it.chain_it != NULL);
    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_chain_filter_iter_w_term_iter() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_add_id(world, e_1, TagB);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_add_id(world, e_2, TagB);

    ecs_new(world, TagA); /* Matches filter 1, not filter 2 */

    ecs_filter_t f_1 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_1,
        .terms = {{ TagA }}
    }));

    ecs_iter_t child_it = ecs_filter_iter(world, &f_1);
    ecs_iter_t it = ecs_term_chain_iter(&child_it, &(ecs_term_t){ TagB });
    test_int(it.field_count, 1);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), TagB);
    test_int(ecs_field_src(&it, 1), 0);
    test_assert(it.table != NULL);
    test_assert(it.chain_it != NULL);

    test_assert(!ecs_term_next(&it));

    ecs_filter_fini(&f_1);

    ecs_fini(world);
}

void Filter_chain_w_term_iter_component() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_COMPONENT(world, Position);

    ecs_entity_t e_1 = ecs_set(world, 0, Position, {10, 20});
    ecs_add_id(world, e_1, TagA);
    ecs_entity_t e_2 = ecs_set(world, 0, Position, {30, 40});
    ecs_add_id(world, e_2, TagA);

    ecs_new(world, TagA); /* Matches filter 1, not filter 2 */

    ecs_iter_t child_it = ecs_term_iter(world, &(ecs_term_t) { TagA });
    ecs_iter_t it = ecs_term_chain_iter(&child_it, &(ecs_term_t) { ecs_id(Position) });
    test_int(it.field_count, 1);

    test_assert(ecs_term_next(&it));
    test_int(it.count, 2);
    test_int(it.entities[0], e_1);
    test_int(it.entities[1], e_2);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1), 0);
    test_assert(it.table != NULL);

    Position *ptr = ecs_field(&it, Position, 1);
    test_assert(ptr != NULL);
    test_int(ptr[0].x, 10);
    test_int(ptr[0].y, 20);
    test_int(ptr[1].x, 30);
    test_int(ptr[1].y, 40);

    test_assert(!ecs_term_next(&it));

    ecs_fini(world);
}

void Filter_chain_iter_w_or() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);

    ecs_entity_t e_1 = ecs_new(world, TagA);
    ecs_add_id(world, e_1, TagB);
    ecs_entity_t e_2 = ecs_new(world, TagA);
    ecs_add_id(world, e_2, TagC);

    ecs_filter_t f_1 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_1,
        .terms = {{ TagA }}
    }));

    ecs_filter_t f_2 = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f_2,
        .terms = {{ TagB, .oper = EcsOr }, { TagC }}
    }));

    ecs_iter_t child_it = ecs_filter_iter(world, &f_1);
    ecs_iter_t it = ecs_filter_chain_iter(&child_it, &f_2);
    test_int(it.field_count, 1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_1);
    test_int(ecs_field_id(&it, 1), TagB);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_int(it.entities[0], e_2);
    test_int(ecs_field_id(&it, 1), TagC);
    test_int(ecs_field_src(&it, 1), 0);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f_1);
    ecs_filter_fini(&f_2);

    ecs_fini(world);
}

void Filter_filter_from_expr_2_terms_err() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Foo);

    ecs_log_set_level(-4);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL == ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "Foo, (IsA"
    }));

    ecs_fini(world);
}

void Filter_filter_w_recycled_first() {
    ecs_world_t *world = ecs_mini();

    ecs_entity_t rel = ecs_new_id(world);
    ecs_entity_t obj = ecs_new_id(world);
    ecs_delete(world, rel);
    
    ecs_entity_t rel2 = ecs_new_id(world);
    test_assert(rel != rel2);
    test_assert((uint32_t)rel == (uint32_t)rel2);

    ecs_entity_t e = ecs_new_w_pair(world, rel2, obj);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f, 
        .terms = {{ .first.id = rel2, .second.id = obj }}
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_int(it.ids[0], ecs_pair(rel2, obj));
    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_recycled_second() {
    ecs_world_t *world = ecs_mini();

    ecs_entity_t rel = ecs_new_id(world);
    ecs_entity_t obj = ecs_new_id(world);
    ecs_delete(world, obj);
    
    ecs_entity_t obj2 = ecs_new_id(world);
    test_assert(obj != obj2);
    test_assert((uint32_t)obj == (uint32_t)obj2);

    ecs_entity_t e = ecs_new_w_pair(world, rel, obj2);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f, 
        .terms = {{ .first.id = rel, .second.id = obj2 }}
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_int(it.ids[0], ecs_pair(rel, obj2));
    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_recycled_first_and_id() {
    ecs_world_t *world = ecs_mini();

    ecs_entity_t rel = ecs_new_id(world);
    ecs_entity_t obj = ecs_new_id(world);
    ecs_delete(world, rel);
    
    ecs_entity_t rel2 = ecs_new_id(world);
    test_assert(rel != rel2);
    test_assert((uint32_t)rel == (uint32_t)rel2);

    ecs_entity_t e = ecs_new_w_pair(world, rel2, obj);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f, 
        .terms = {{ .id = ecs_pair(rel2, obj), .first.id = rel2 }}
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_int(it.ids[0], ecs_pair(rel2, obj));
    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_recycled_second_and_id() {
    ecs_world_t *world = ecs_mini();

    ecs_entity_t rel = ecs_new_id(world);
    ecs_entity_t obj = ecs_new_id(world);
    ecs_delete(world, obj);
    
    ecs_entity_t obj2 = ecs_new_id(world);
    test_assert(obj != obj2);
    test_assert((uint32_t)obj == (uint32_t)obj2);

    ecs_entity_t e = ecs_new_w_pair(world, rel, obj2);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f, 
        .terms = {{ .id = ecs_pair(rel, obj2), .second.id = obj2 }}
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_int(it.ids[0], ecs_pair(rel, obj2));
    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_recycled_first_by_name_and_id() {
    ecs_world_t *world = ecs_mini();

    ecs_entity_t rel = ecs_new_id(world);
    ecs_entity_t obj = ecs_new_id(world);
    ecs_delete(world, rel);
    
    ecs_entity_t rel2 = ecs_new_id(world);
    test_assert(rel != rel2);
    test_assert((uint32_t)rel == (uint32_t)rel2);
    ecs_set_name(world, rel2, "rel");

    ecs_entity_t e = ecs_new_w_pair(world, rel2, obj);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f, 
        .terms = {{ .id = ecs_pair(rel2, obj), .first.name = "rel" }}
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_int(it.ids[0], ecs_pair(rel2, obj));
    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_recycled_second_by_name_and_id() {
    ecs_world_t *world = ecs_mini();

    ecs_entity_t rel = ecs_new_id(world);
    ecs_entity_t obj = ecs_new_id(world);
    ecs_delete(world, obj);
    
    ecs_entity_t obj2 = ecs_new_id(world);
    test_assert(obj != obj2);
    test_assert((uint32_t)obj == (uint32_t)obj2);
    ecs_set_name(world, obj2, "obj");

    ecs_entity_t e = ecs_new_w_pair(world, rel, obj2);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f, 
        .terms = {{ .id = ecs_pair(rel, obj2), .second.name = "obj" }}
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_int(it.ids[0], ecs_pair(rel, obj2));
    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_recycled_first_by_expr() {
    ecs_world_t *world = ecs_mini();

    ecs_entity_t rel = ecs_new_id(world);
    ecs_entity_t obj = ecs_new_id(world);
    ecs_delete(world, rel);
    
    ecs_entity_t rel2 = ecs_new_id(world);
    test_assert(rel != rel2);
    test_assert((uint32_t)rel == (uint32_t)rel2);
    
    ecs_set_name(world, rel2, "rel");
    ecs_set_name(world, obj, "obj");

    ecs_entity_t e = ecs_new_w_pair(world, rel2, obj);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f, 
        .expr = "(rel, obj)"
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_int(it.ids[0], ecs_pair(rel2, obj));
    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_recycled_second_by_expr() {
    ecs_world_t *world = ecs_mini();

    ecs_entity_t rel = ecs_new_id(world);
    ecs_entity_t obj = ecs_new_id(world);
    ecs_delete(world, obj);
    
    ecs_entity_t obj2 = ecs_new_id(world);
    test_assert(obj != obj2);
    test_assert((uint32_t)obj == (uint32_t)obj2);
    
    ecs_set_name(world, rel, "rel");
    ecs_set_name(world, obj2, "obj");

    ecs_entity_t e = ecs_new_w_pair(world, rel, obj2);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f, 
        .expr = "(rel, obj)"
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_int(it.ids[0], ecs_pair(rel, obj2));
    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_recycled_first_only_by_expr() {
    ecs_world_t *world = ecs_mini();

    ecs_entity_t rel = ecs_new_id(world);
    ecs_delete(world, rel);
    
    ecs_entity_t rel2 = ecs_new_id(world);
    test_assert(rel != rel2);
    test_assert((uint32_t)rel == (uint32_t)rel2);
    
    ecs_set_name(world, rel2, "rel");

    ecs_entity_t e = ecs_new_w_id(world, rel2);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f, 
        .expr = "rel"
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_int(it.ids[0], rel2);
    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_term_iter_w_filter_term() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);

    ecs_entity_t e = ecs_set(world, 0, Position, {10, 20});

    ecs_iter_t it = ecs_term_iter(world, &(ecs_term_t) { 
        .id = ecs_id(Position),
        .inout = EcsInOutNone
    });

    test_bool(ecs_term_next(&it), true);
    test_assert(it.ids != NULL);
    test_assert(it.ids[0] == ecs_id(Position));

    test_int(it.count, 1);
    test_assert(it.entities != NULL);
    test_assert(it.entities[0] == e);

    test_assert(it.sizes != NULL);
    test_int(it.sizes[0], ECS_SIZEOF(Position));

    test_assert(it.ptrs != NULL);
    test_assert(it.columns != NULL);
    test_assert(it.ptrs[0] == NULL);

    test_bool(ecs_term_next(&it), false);

    ecs_fini(world);
}

void Filter_filter_iter_w_filter_term() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .id = ecs_id(Position), .inout = EcsInOutNone }}
    }));

    test_bool(f.flags & EcsFilterNoData, true);

    ecs_entity_t e = ecs_set(world, 0, Position, {10, 20});

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_bool(ecs_filter_next(&it), true);
    test_assert(it.ids != NULL);
    test_assert(it.ids[0] == ecs_id(Position));

    test_int(it.count, 1);
    test_assert(it.entities != NULL);
    test_assert(it.entities[0] == e);
    test_assert(it.sizes != NULL);
    test_int(it.sizes[0], ECS_SIZEOF(Position));

    test_assert(it.ptrs != NULL);
    test_assert(it.columns != NULL);
    test_assert(it.ptrs[0] == NULL);

    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_w_2_terms_1_filter() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .id = ecs_id(Position), .inout = EcsInOutNone },
            { .id = ecs_id(Velocity) }
        }
    }));

    ecs_entity_t e = ecs_set(world, 0, Position, {10, 20});
    ecs_set(world, e, Velocity, {1, 1});

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_bool(ecs_filter_next(&it), true);
    test_assert(it.ids != NULL);
    test_assert(it.ids[0] == ecs_id(Position));
    test_assert(it.ids[1] == ecs_id(Velocity));

    test_int(it.count, 1);
    test_assert(it.entities != NULL);
    test_assert(it.entities[0] == e);

    test_assert(it.sizes != NULL);
    test_int(it.sizes[0], ECS_SIZEOF(Position));
    test_int(it.sizes[1], ECS_SIZEOF(Velocity));

    test_assert(it.ptrs != NULL);
    test_assert(it.columns != NULL);

    test_assert(it.ptrs[0] == NULL);
    test_assert(it.ptrs[1] != NULL);

    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_w_3_terms_2_filter() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);
    ECS_COMPONENT(world, Mass);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .id = ecs_id(Position), .inout = EcsInOutNone },
            { .id = ecs_id(Velocity), .inout = EcsInOutNone },
            { .id = ecs_id(Mass) }
        }
    }));

    ecs_entity_t e = ecs_set(world, 0, Position, {10, 20});
    ecs_set(world, e, Velocity, {1, 1});
    ecs_set(world, e, Mass, {1});

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_bool(ecs_filter_next(&it), true);
    test_assert(it.ids != NULL);
    test_assert(it.ids[0] == ecs_id(Position));
    test_assert(it.ids[1] == ecs_id(Velocity));
    test_assert(it.ids[2] == ecs_id(Mass));

    test_int(it.count, 1);
    test_assert(it.entities != NULL);
    test_assert(it.entities[0] == e);

    test_assert(it.sizes != NULL);
    test_int(it.sizes[0], ECS_SIZEOF(Position));
    test_int(it.sizes[1], ECS_SIZEOF(Velocity));
    test_int(it.sizes[2], ECS_SIZEOF(Mass));

    test_assert(it.ptrs != NULL);
    test_assert(it.columns != NULL);

    test_assert(it.ptrs[0] == NULL);
    test_assert(it.ptrs[1] == NULL);
    test_assert(it.ptrs[2] != NULL);

    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}


void Filter_filter_iter_2_terms_filter_all() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .id = ecs_id(Position), .inout = EcsInOutNone },
            { .id = ecs_id(Velocity) }
        },
        .flags = EcsFilterNoData
    }));

    ecs_entity_t e = ecs_set(world, 0, Position, {10, 20});
    ecs_set(world, e, Velocity, {1, 1});

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_bool(ecs_filter_next(&it), true);
    test_assert(it.ids != NULL);
    test_assert(it.ids[0] == ecs_id(Position));
    test_assert(it.ids[1] == ecs_id(Velocity));

    test_int(it.count, 1);
    test_assert(it.entities != NULL);
    test_assert(it.entities[0] == e);

    test_assert(it.sizes != NULL);
    test_int(it.sizes[0], ECS_SIZEOF(Position));
    test_int(it.sizes[1], ECS_SIZEOF(Velocity));

    test_assert(it.ptrs != NULL);
    test_assert(it.columns != NULL);
    test_assert(it.ptrs[0] == NULL);

    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_2_terms_filter_all_w_out() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .id = ecs_id(Position), .inout = EcsOut },
            { .id = ecs_id(Velocity) }
        },
        .flags = EcsFilterNoData
    }));

    ecs_entity_t e = ecs_set(world, 0, Position, {10, 20});
    ecs_set(world, e, Velocity, {1, 1});

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_bool(ecs_filter_next(&it), true);
    test_assert(it.ids != NULL);
    test_assert(it.ids[0] == ecs_id(Position));
    test_assert(it.ids[1] == ecs_id(Velocity));

    test_int(it.count, 1);
    test_assert(it.entities != NULL);
    test_assert(it.entities[0] == e);

    test_assert(it.sizes != NULL);
    test_int(it.sizes[0], ECS_SIZEOF(Position));
    test_int(it.sizes[1], ECS_SIZEOF(Velocity));

    test_assert(it.ptrs != NULL);
    test_assert(it.columns != NULL);
    test_assert(it.ptrs[0] == NULL);

    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_switch_term_filter() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Sw, Union);
    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e = ecs_new_w_pair(world, Sw, TagA);
    ecs_table_t *table = ecs_get_table(world, e);
    
    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .id = ecs_pair(Sw, EcsWildcard), .inout = EcsInOutNone }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);
    
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_int(it.sizes[0], ECS_SIZEOF(ecs_entity_t));
    test_assert(it.table == table);

    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_2_terms_switch_term_filter() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Sw, Union);
    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_COMPONENT(world, Position);

    ecs_entity_t e = ecs_new_w_pair(world, Sw, TagA);
    ecs_add(world, e, Position);
    ecs_table_t *table = ecs_get_table(world, e);
    
    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .id = ecs_id(Position) },
            { .id = ecs_pair(Sw, EcsWildcard), .inout = EcsInOutNone }
        }
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);
    
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_int(it.sizes[0], ECS_SIZEOF(Position));
    test_int(it.sizes[1], ECS_SIZEOF(ecs_entity_t));
    test_assert(it.table == table);

    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_instanced_w_singleton() {
    ecs_world_t *world = ecs_mini();
    
    ECS_TAG(world, Tag);

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);

    ecs_singleton_set(world, Velocity, {1, 2});

    ecs_entity_t e1 = ecs_set(world, 0, Position, {10, 20});
    ecs_entity_t e2 = ecs_set(world, 0, Position, {20, 30});
    ecs_entity_t e3 = ecs_set(world, 0, Position, {30, 40});

    ecs_entity_t e4 = ecs_set(world, 0, Position, {40, 50});
    ecs_entity_t e5 = ecs_set(world, 0, Position, {50, 60});

    ecs_add(world, e4, Tag);
    ecs_add(world, e5, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "Position, Velocity($)",
        .instanced = true
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_assert(ecs_filter_next(&it));
    {
        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 3);
        test_int(it.entities[0], e1);
        test_int(it.entities[1], e2);
        test_int(it.entities[2], e3);
        test_int(v->x, 1);
        test_int(v->y, 2);
        test_int(p[0].x, 10);
        test_int(p[0].y, 20);
        test_int(p[1].x, 20);
        test_int(p[1].y, 30);
        test_int(p[2].x, 30);
        test_int(p[2].y, 40);
    }

    test_assert(ecs_filter_next(&it));
    {
        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 2);
        test_int(it.entities[0], e4);
        test_int(it.entities[1], e5);
        test_int(p[0].x, 40);
        test_int(p[0].y, 50);
        test_int(p[1].x, 50);
        test_int(p[1].y, 60);
        test_int(v->x, 1);
        test_int(v->y, 2);
    }

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_instanced_w_base() {
    ecs_world_t *world = ecs_mini();
    
    ECS_TAG(world, Tag);

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);

    ecs_entity_t base_1 = ecs_set(world, 0, Velocity, {1, 2});
    ecs_entity_t base_2 = ecs_set(world, 0, Position, {80, 90});

    ecs_entity_t e1 = ecs_set(world, 0, Position, {10, 20});
    ecs_entity_t e2 = ecs_set(world, 0, Position, {20, 30});
    ecs_entity_t e3 = ecs_set(world, 0, Position, {30, 40});

    ecs_entity_t e4 = ecs_set(world, 0, Position, {40, 50});
    ecs_entity_t e5 = ecs_set(world, 0, Position, {50, 60});
    ecs_add(world, e4, Tag);
    ecs_add(world, e5, Tag);

    ecs_add_pair(world, e1, EcsIsA, base_1);
    ecs_add_pair(world, e2, EcsIsA, base_1);
    ecs_add_pair(world, e3, EcsIsA, base_1);
    ecs_add_pair(world, e4, EcsIsA, base_1);
    ecs_add_pair(world, e5, EcsIsA, base_1);

    ecs_entity_t e6 = ecs_set(world, 0, Position, {60, 70});
    ecs_entity_t e7 = ecs_set(world, 0, Position, {70, 80});
    ecs_set(world, e6, Velocity, {2, 3});
    ecs_set(world, e7, Velocity, {4, 5});

    ecs_entity_t e8 = ecs_set(world, 0, Velocity, {6, 7});
    ecs_entity_t e9 = ecs_set(world, 0, Velocity, {8, 9});
    ecs_add_pair(world, e8, EcsIsA, base_2);
    ecs_add_pair(world, e9, EcsIsA, base_2);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "Position, Velocity",
        .instanced = true
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    {
        test_bool(ecs_field_is_self(&it, 1), true);
        test_bool(ecs_field_is_self(&it, 2), true);

        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 2);
        test_int(it.entities[0], e6);
        test_int(p[0].x, 60);
        test_int(p[0].y, 70);
        test_int(v[0].x, 2);
        test_int(v[0].y, 3);

        test_int(it.entities[1], e7);
        test_int(p[1].x, 70);
        test_int(p[1].y, 80);
        test_int(v[1].x, 4);
        test_int(v[1].y, 5);
    }

    test_assert(ecs_filter_next(&it));
    {
        test_bool(ecs_field_is_self(&it, 1), false);
        test_bool(ecs_field_is_self(&it, 2), true);

        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 2);
        test_int(it.entities[0], e8);
        test_int(it.entities[1], e9);
        test_int(p->x, 80);
        test_int(p->y, 90);
        test_int(v[0].x, 6);
        test_int(v[0].y, 7);
        test_int(v[1].x, 8);
        test_int(v[1].y, 9);
    }

    test_assert(ecs_filter_next(&it));
    {
        test_bool(ecs_field_is_self(&it, 1), true);
        test_bool(ecs_field_is_self(&it, 2), false);

        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);

        test_int(it.count, 3);
        test_int(it.entities[0], e1);
        test_int(it.entities[1], e2);
        test_int(it.entities[2], e3);
        test_int(p[0].x, 10);
        test_int(p[0].y, 20);
        test_int(p[1].x, 20);
        test_int(p[1].y, 30);
        test_int(p[2].x, 30);
        test_int(p[2].y, 40);
        test_int(v->x, 1);
        test_int(v->y, 2);
    }

    test_assert(ecs_filter_next(&it));
    {
        test_bool(ecs_field_is_self(&it, 1), true);
        test_bool(ecs_field_is_self(&it, 2), false);

        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 2);
        test_int(it.entities[0], e4);
        test_int(it.entities[1], e5);
        test_int(p[0].x, 40);
        test_int(p[0].y, 50);
        test_int(p[1].x, 50);
        test_int(p[1].y, 60);
        test_int(v->x, 1);
        test_int(v->y, 2);
    }

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_no_instancing_w_singleton() {
    ecs_world_t *world = ecs_mini();
    
    ECS_TAG(world, Tag);

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);

    ecs_singleton_set(world, Velocity, {1, 2});

    ecs_entity_t e1 = ecs_set(world, 0, Position, {10, 20});
    ecs_entity_t e2 = ecs_set(world, 0, Position, {20, 30});
    ecs_entity_t e3 = ecs_set(world, 0, Position, {30, 40});

    ecs_entity_t e4 = ecs_set(world, 0, Position, {40, 50});
    ecs_entity_t e5 = ecs_set(world, 0, Position, {50, 60});

    ecs_add(world, e4, Tag);
    ecs_add(world, e5, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "Position, Velocity($)"
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_assert(ecs_filter_next(&it));
    {
        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 1);
        test_int(it.entities[0], e1);
        test_int(p->x, 10);
        test_int(p->y, 20);
        test_int(v->x, 1);
        test_int(v->y, 2);
    }

    test_assert(ecs_filter_next(&it));
    {
        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 1);
        test_int(it.entities[0], e2);
        test_int(p->x, 20);
        test_int(p->y, 30);
        test_int(v->x, 1);
        test_int(v->y, 2);
    }

    test_assert(ecs_filter_next(&it));
    {
        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 1);
        test_int(it.entities[0], e3);
        test_int(p->x, 30);
        test_int(p->y, 40);
        test_int(v->x, 1);
        test_int(v->y, 2);
    }

    test_assert(ecs_filter_next(&it));
    {
        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 1);
        test_int(it.entities[0], e4);
        test_int(p->x, 40);
        test_int(p->y, 50);
        test_int(v->x, 1);
        test_int(v->y, 2);
    }

    test_assert(ecs_filter_next(&it));
    {
        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 1);
        test_int(it.entities[0], e5);
        test_int(p->x, 50);
        test_int(p->y, 60);
        test_int(v->x, 1);
        test_int(v->y, 2);
    }

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_no_instancing_w_base() {
    ecs_world_t *world = ecs_mini();
    
    ECS_TAG(world, Tag);

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);

    ecs_entity_t base_1 = ecs_set(world, 0, Velocity, {1, 2});
    ecs_entity_t base_2 = ecs_set(world, 0, Position, {80, 90});

    ecs_entity_t e1 = ecs_set(world, 0, Position, {10, 20});
    ecs_entity_t e2 = ecs_set(world, 0, Position, {20, 30});
    ecs_entity_t e3 = ecs_set(world, 0, Position, {30, 40});

    ecs_entity_t e4 = ecs_set(world, 0, Position, {40, 50});
    ecs_entity_t e5 = ecs_set(world, 0, Position, {50, 60});
    ecs_add(world, e4, Tag);
    ecs_add(world, e5, Tag);

    ecs_add_pair(world, e1, EcsIsA, base_1);
    ecs_add_pair(world, e2, EcsIsA, base_1);
    ecs_add_pair(world, e3, EcsIsA, base_1);
    ecs_add_pair(world, e4, EcsIsA, base_1);
    ecs_add_pair(world, e5, EcsIsA, base_1);

    ecs_entity_t e6 = ecs_set(world, 0, Position, {60, 70});
    ecs_entity_t e7 = ecs_set(world, 0, Position, {70, 80});
    ecs_set(world, e6, Velocity, {2, 3});
    ecs_set(world, e7, Velocity, {4, 5});

    ecs_entity_t e8 = ecs_set(world, 0, Velocity, {6, 7});
    ecs_entity_t e9 = ecs_set(world, 0, Velocity, {8, 9});
    ecs_add_pair(world, e8, EcsIsA, base_2);
    ecs_add_pair(world, e9, EcsIsA, base_2);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "Position, Velocity"
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    {
        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 2);
        test_int(it.entities[0], e6);
        test_int(p[0].x, 60);
        test_int(p[0].y, 70);
        test_int(v[0].x, 2);
        test_int(v[0].y, 3);

        test_int(it.entities[1], e7);
        test_int(p[1].x, 70);
        test_int(p[1].y, 80);
        test_int(v[1].x, 4);
        test_int(v[1].y, 5);
    }

    test_assert(ecs_filter_next(&it));
    {
        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 1);
        test_int(it.entities[0], e8);
        test_int(p->x, 80);
        test_int(p->y, 90);
        test_int(v->x, 6);
        test_int(v->y, 7);
    }

    test_assert(ecs_filter_next(&it));
    {
        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 1);
        test_int(it.entities[0], e9);
        test_int(p->x, 80);
        test_int(p->y, 90);
        test_int(v->x, 8);
        test_int(v->y, 9);
    }

    test_assert(ecs_filter_next(&it));
    {
        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);

        test_int(it.count, 1);
        test_int(it.entities[0], e1);
        test_int(p->x, 10);
        test_int(p->y, 20);
        test_int(v->x, 1);
        test_int(v->y, 2);
    }

    test_assert(ecs_filter_next(&it));
    {
        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 1);
        test_int(it.entities[0], e2);
        test_int(p->x, 20);
        test_int(p->y, 30);
        test_int(v->x, 1);
        test_int(v->y, 2);
    }

    test_assert(ecs_filter_next(&it));
    {
        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 1);
        test_int(it.entities[0], e3);
        test_int(p->x, 30);
        test_int(p->y, 40);
        test_int(v->x, 1);
        test_int(v->y, 2);
    }

    test_assert(ecs_filter_next(&it));
    {
        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 1);
        test_int(it.entities[0], e4);
        test_int(p->x, 40);
        test_int(p->y, 50);
        test_int(v->x, 1);
        test_int(v->y, 2);
    }

    test_assert(ecs_filter_next(&it));
    {
        Position *p = ecs_field(&it, Position, 1);
        Velocity *v = ecs_field(&it, Velocity, 2);
        test_int(it.count, 1);
        test_int(it.entities[0], e5);
        test_int(p->x, 50);
        test_int(p->y, 60);
        test_int(v->x, 1);
        test_int(v->y, 2);
    }

    test_assert(!ecs_filter_next(&it));
    
    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_no_this_tag() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);

    ecs_entity_t e = ecs_set_name(world, 0, "e");
    ecs_add(world, e, Tag);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "Tag(e)",
    }));

    test_assert(!(f.flags & EcsFilterMatchThis));
    test_assert(!(f.flags & EcsFilterMatchAnything));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 0);
    test_int(ecs_field_id(&it, 1), Tag);
    test_int(ecs_field_src(&it, 1),  e); 

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_no_this_component() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);

    ecs_entity_t e = ecs_set_name(world, 0, "e");
    ecs_set(world, e, Position, {10, 20});

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "Position(e)",
    }));

    test_assert(!(f.flags & EcsFilterMatchThis));
    test_assert(!(f.flags & EcsFilterMatchAnything));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 0);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1),  e);

    Position *p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_no_this_tag_2_ents() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e1 = ecs_set_name(world, 0, "e1");
    ecs_add(world, e1, TagA);
    ecs_entity_t e2 = ecs_set_name(world, 0, "e2");
    ecs_add(world, e2, TagB);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "TagA(e1), TagB(e2)",
    }));

    test_assert(!(f.flags & EcsFilterMatchThis));
    test_assert(!(f.flags & EcsFilterMatchAnything));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 0);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_src(&it, 1),  e1);
    test_int(ecs_field_id(&it, 2), TagB);
    test_int(ecs_field_src(&it, 2),  e2);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_no_this_component_2_ents() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);

    ecs_entity_t e1 = ecs_set_name(world, 0, "e1");
    ecs_set(world, e1, Position, {10, 20});
    ecs_entity_t e2 = ecs_set_name(world, 0, "e2");
    ecs_set(world, e2, Velocity, {1, 2});

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "Position(e1), Velocity(e2)",
    }));

    test_assert(!(f.flags & EcsFilterMatchThis));
    test_assert(!(f.flags & EcsFilterMatchAnything));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 0);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1),  e1);
    test_int(ecs_field_id(&it, 2), ecs_id(Velocity));
    test_int(ecs_field_src(&it, 2),  e2);

    Position *p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);

    Velocity *v = ecs_field(&it, Velocity, 2);
    test_assert(p != NULL);
    test_int(v->x, 1);
    test_int(v->y, 2);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_no_this_tag_2_ents_1_not() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e1 = ecs_set_name(world, 0, "e1");
    ecs_add(world, e1, TagA);
    ecs_entity_t e2 = ecs_set_name(world, 0, "e2");
    ecs_add(world, e2, TagB);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "TagA(e1), TagB(e2), !TagA(e2)",
    }));

    test_assert(!(f.flags & EcsFilterMatchThis));
    test_assert(!(f.flags & EcsFilterMatchAnything));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 0);
    test_int(ecs_field_id(&it, 1), TagA);
    test_int(ecs_field_src(&it, 1),  e1);
    test_int(ecs_field_id(&it, 2), TagB);
    test_int(ecs_field_src(&it, 2),  e2);
    test_int(ecs_field_id(&it, 3), TagA);
    test_int(ecs_field_src(&it, 3),  e2);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_no_this_component_2_ents_1_not() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);

    ecs_entity_t e1 = ecs_set_name(world, 0, "e1");
    ecs_set(world, e1, Position, {10, 20});
    ecs_entity_t e2 = ecs_set_name(world, 0, "e2");
    ecs_set(world, e2, Velocity, {1, 2});

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "Position(e1), Velocity(e2), !Position(e2)",
    }));

    test_assert(!(f.flags & EcsFilterMatchThis));
    test_assert(!(f.flags & EcsFilterMatchAnything));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 0);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1),  e1);
    test_int(ecs_field_id(&it, 2), ecs_id(Velocity));
    test_int(ecs_field_src(&it, 2),  e2);
    test_int(ecs_field_id(&it, 3), ecs_id(Position));
    test_int(ecs_field_src(&it, 3),  e2);

    Position *p = ecs_field(&it, Position, 1);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);

    Velocity *v = ecs_field(&it, Velocity, 2);
    test_assert(p != NULL);
    test_int(v->x, 1);
    test_int(v->y, 2);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_no_this_component_1_not() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);

    ecs_entity_t e1 = ecs_set_name(world, 0, "e1");

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "!Position(e1)",
    }));

    test_assert(!(f.flags & EcsFilterMatchThis));
    test_assert(!(f.flags & EcsFilterMatchAnything));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 0);
    test_int(ecs_field_id(&it, 1), ecs_id(Position));
    test_int(ecs_field_src(&it, 1),  e1);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_entities_optional_flag() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_entity_t e2 = ecs_new_entity(world, "e");

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "TagA, TagB(e)",
    }));

    /* e2 doesn't have TagB, so regular iteration doesn't return anything */
    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(false, ecs_filter_next(&it));

    /* Treat terms matched on entities as optional */
    it = ecs_filter_iter(world, &f);
    it.flags |= EcsIterEntityOptional;

    test_bool(true, ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e1);
    test_uint(it.sources[0], 0);
    test_uint(it.sources[1], e2);
    test_uint(ecs_field_id(&it, 1), TagA);
    test_uint(ecs_field_id(&it, 2), TagB);
    test_bool(true, ecs_field_is_set(&it, 1));
    test_bool(false, ecs_field_is_set(&it, 2));
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_frame_offset() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .id = TagA, }
        },
    }));

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_entity_t e2 = ecs_new(world, TagA);
    ecs_entity_t e3 = ecs_new(world, TagA);
    ecs_entity_t e4 = ecs_new(world, TagA);
    ecs_entity_t e5 = ecs_new(world, TagA);

    ecs_add(world, e3, TagB);
    ecs_add(world, e4, TagB);
    ecs_add(world, e5, TagC);

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 2);
    test_int(it.frame_offset, 0);
    test_assert(it.entities != NULL);
    test_assert(it.entities[0] == e1);
    test_assert(it.entities[1] == e2);
    test_assert(it.ids[0] == TagA);

    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 2);
    test_int(it.frame_offset, 2);
    test_assert(it.entities != NULL);
    test_assert(it.entities[0] == e3);
    test_assert(it.entities[1] == e4);
    test_assert(it.ids[0] == TagA);

    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.frame_offset, 4);
    test_assert(it.entities != NULL);
    test_assert(it.entities[0] == e5);
    test_assert(it.ids[0] == TagA);

    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_1_term_no_alloc() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_term_t terms[1];
    ecs_filter_t f = ECS_FILTER_INIT;
    f.terms = terms;
    f.term_count = 1;

    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { .id = TagA, }
        },
    }));

    test_assert(terms == f.terms);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_cache_size_terms_no_alloc() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, TagD);

    ecs_term_t terms[4];
    ecs_filter_t f = ECS_FILTER_INIT;
    f.terms = terms;
    f.term_count = 4;

    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }, { TagB }, { TagC }, { TagD }}
    }));

    test_assert(terms == f.terms);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_lt_cache_size_terms_no_alloc() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, TagD);
    ECS_TAG(world, TagE);

    ecs_term_t terms[5];
    ecs_filter_t f = ECS_FILTER_INIT;
    f.terms = terms;
    f.term_count = 5;

    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }, { TagB }, { TagC }, { TagD }, { TagE }}
    }));

    test_assert(terms == f.terms);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_move_self() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }}
    }));

    ecs_filter_t f_2 = f;
    ecs_filter_move(&f_2, &f_2);

    char *str = ecs_filter_str(world, &f_2);
    test_str(str, "TagA");
    ecs_os_free(str);

    ecs_filter_fini(&f_2);

    ecs_fini(world);
}

void Filter_match_empty_tables() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    
    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);

    ecs_entity_t e1 = ecs_new(world, Position);
    ecs_entity_t e2 = ecs_new(world, Position);
    ecs_entity_t e3 = ecs_new(world, Position);
    ecs_entity_t e4 = ecs_new(world, Position);

    ecs_add(world, e2, TagA);
    ecs_add(world, e3, TagB);
    ecs_add(world, e4, TagC);

    ecs_table_t *t1 = ecs_get_table(world, e1);
    ecs_table_t *t2 = ecs_get_table(world, e2);
    ecs_table_t *t3 = ecs_get_table(world, e3);
    ecs_table_t *t4 = ecs_get_table(world, e4);

    ecs_delete(world, e1);
    ecs_delete(world, e2);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ ecs_id(Position) }},
        .flags = EcsFilterMatchEmptyTables
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);
    
    test_bool( ecs_filter_next(&it), true);
    test_assert(it.table == t1);
    test_int(it.count, 0);
    test_uint(ecs_field_id(&it, 1), ecs_id(Position));
    test_uint(ecs_field_size(&it, 1), sizeof(Position));

    test_bool( ecs_filter_next(&it), true);
    test_assert(it.table == t2);
    test_int(it.count, 0);
    test_uint(ecs_field_id(&it, 1), ecs_id(Position));
    test_uint(ecs_field_size(&it, 1), sizeof(Position));

    test_bool( ecs_filter_next(&it), true);
    test_assert(it.table == t3);
    test_int(it.count, 1);
    test_int(it.entities[0], e3);
    test_uint(ecs_field_id(&it, 1), ecs_id(Position));
    test_uint(ecs_field_size(&it, 1), sizeof(Position));

    test_bool( ecs_filter_next(&it), true);
    test_assert(it.table == t4);
    test_int(it.count, 1);
    test_int(it.entities[0], e4);
    test_uint(ecs_field_id(&it, 1), ecs_id(Position));
    test_uint(ecs_field_size(&it, 1), sizeof(Position));

    test_bool( ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_match_empty_tables_w_no_empty_tables() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Foo);
    ECS_TAG(world, Bar);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { Foo }
        },
        .flags = EcsFilterMatchEmptyTables
    }));

    ecs_entity_t e1 = ecs_new(world, Foo);
    ecs_entity_t e2 = ecs_new(world, Foo);
    ecs_add(world, e2, Bar);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e2, it.entities[0]);

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_match_switch_w_switch() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Sw, Union);
    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e = ecs_new_w_pair(world, Sw, TagA);
    ecs_table_t *table = ecs_get_table(world, e);
    
    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ ecs_pair(Sw, EcsWildcard) }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);
    
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_int(it.sizes[0], ECS_SIZEOF(ecs_entity_t));
    test_uint(it.ids[0], ecs_pair(Sw, EcsWildcard));
    test_assert(it.table == table);

    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_match_switch_w_case() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Sw, Union);
    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e = ecs_new_w_pair(world, Sw, TagA);
    ecs_table_t *table = ecs_get_table(world, e);
    
    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ ecs_pair(Sw, TagA) }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_assert(it.table == table);
    test_uint(it.ids[0], ecs_pair(Sw, EcsWildcard));

    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_match_switch_w_case_2_terms() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, SwX, Union);
    ECS_ENTITY(world, SwY, Union);
    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, TagD);

    ecs_entity_t e = ecs_new_w_pair(world, SwX, TagA);
    ecs_add_pair(world, e, SwY, TagC);
    ecs_table_t *table = ecs_get_table(world, e);

    /* Not matched */
    ecs_new_w_pair(world, SwX, TagA);
    ecs_new_w_pair(world, SwY, TagC);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { ecs_pair(SwX, TagA) },
            { ecs_pair(SwY, TagC) }
        }
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);
    
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_assert(it.table == table);
    test_uint(it.ids[0], ecs_pair(SwX, EcsWildcard));
    test_uint(it.ids[1], ecs_pair(SwY, EcsWildcard));

    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_iter_switch_superset() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, SwX, Union);
    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t b = ecs_new_w_pair(world, SwX, TagA);
    ecs_entity_t e = ecs_new_w_pair(world, EcsIsA, b);

    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { ecs_pair(SwX, EcsWildcard), .src.flags = EcsUp }
        }
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);
    
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_int(it.sources[0], b);
    test_uint(it.ids[0], ecs_pair(SwX, EcsWildcard));

    ecs_entity_t *cases = ecs_field(&it, ecs_entity_t, 1);
    test_assert(cases != NULL);
    test_uint(cases[0], TagA);

    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_match_case_no_case() {
    ecs_world_t *world = ecs_mini();

    ECS_ENTITY(world, Sw, Union);
    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e = ecs_new_w_pair(world, Sw, TagA);
    ecs_table_t *table = ecs_get_table(world, e);
    
    ecs_filter_t f = ECS_FILTER_INIT;
    ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ ecs_pair(Sw, TagA) }}
    });

    ecs_iter_t it = ecs_filter_iter(world, &f);
    
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e);
    test_assert(it.table == table);
    test_uint(it.ids[0], ecs_pair(Sw, EcsWildcard));

    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_and_term() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Foo);
    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_PREFAB(world, TypeX, TagA, TagB);

    ecs_entity_t e1 = ecs_new_w_id(world, TagA);
    ecs_add(world, e1, TagB);
    ecs_table_t *table1 = ecs_get_table(world, e1);

    ecs_entity_t e2 = ecs_new_w_id(world, TagA);
    ecs_add(world, e2, TagB);
    ecs_add(world, e2, Foo);
    ecs_table_t *table2 = ecs_get_table(world, e2);

    /* Not matched */
    ecs_new(world, TagA);
    ecs_new(world, TagB);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { ECS_AND | TypeX }
        }
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_uint(it.entities[0], e1);
    test_uint(it.ids[0], TypeX);
    test_assert(it.table == table1);

    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_uint(it.entities[0], e2);
    test_uint(it.ids[0], TypeX);
    test_assert(it.table == table2);

    test_bool(ecs_filter_next(&it), false);
    
    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_or_term() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_PREFAB(world, TypeX, TagA, TagB);

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_table_t *table1 = ecs_get_table(world, e1);

    ecs_entity_t e2 = ecs_new(world, TagB);
    ecs_table_t *table2 = ecs_get_table(world, e2);

    ecs_entity_t e3 = ecs_new(world, TagA);
    ecs_add(world, e3, TagB);
    ecs_table_t *table3 = ecs_get_table(world, e3);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {
            { TypeX, .oper = EcsOrFrom }
        }
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    
    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_uint(it.entities[0], e1);
    test_uint(it.ids[0], TagA);
    test_assert(it.table == table1);

    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_uint(it.entities[0], e2);
    test_uint(it.ids[0], TagB);
    test_assert(it.table == table2);

    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_uint(it.entities[0], e3);
    test_uint(it.ids[0], TagA);
    test_assert(it.table == table3);

    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

static
void create_ids(ecs_world_t *world, int count) {
    for (int i = 0; i < count; i ++) {
        ecs_entity_t e = ecs_new_id(world);
        ecs_add_id(world, e, e);
    }
}

void Filter_iter_while_creating_components() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_entity_t e2 = ecs_new(world, TagA);
    ecs_entity_t e3 = ecs_new(world, TagA);

    ecs_add(world, e2, TagB);
    ecs_add(world, e3, TagC);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }}
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e1);

    create_ids(world, 100);

    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e2);

    create_ids(world, 100);

    test_bool(ecs_filter_next(&it), true);
    test_int(it.count, 1);
    test_int(it.entities[0], e3);

    test_bool(ecs_filter_next(&it), false);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_iter_w_this_var_as_entity() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_entity_t e2 = ecs_new(world, TagA);
    ecs_entity_t e3 = ecs_new(world, TagA);
    ecs_entity_t e4 = ecs_new(world, TagA);
    ecs_add(world, e2, TagB);
    ecs_add(world, e3, TagC);
    ecs_add(world, e4, TagC);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }}
    }));

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e1);
    ecs_entity_t this_var = ecs_iter_get_var(&it, this_var_id);
    test_assert(this_var != 0);
    test_assert(this_var == e1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e2);
    this_var = ecs_iter_get_var(&it, this_var_id);
    test_assert(this_var != 0);
    test_assert(this_var == e2);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_uint(it.entities[0], e3);
    test_uint(it.entities[1], e4);
    this_var = ecs_iter_get_var(&it, this_var_id);
    test_assert(this_var == 0); /* more than one entity matches */

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_iter_w_this_var_as_table() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_entity_t e2 = ecs_new(world, TagA);
    ecs_entity_t e3 = ecs_new(world, TagA);
    ecs_entity_t e4 = ecs_new(world, TagA);
    ecs_add(world, e2, TagB);
    ecs_add(world, e3, TagC);
    ecs_add(world, e4, TagC);

    ecs_table_t *t1 = ecs_get_table(world, e1);
    test_assert(t1 != NULL);

    ecs_table_t *t2 = ecs_get_table(world, e2);
    test_assert(t2 != NULL);
    test_assert(t2 != t1);

    ecs_table_t *t3 = ecs_get_table(world, e3);
    test_assert(t3 != NULL);
    test_assert(t3 != t1);
    test_assert(t3 != t2);
    test_assert(t3 == ecs_get_table(world, e4));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }}
    }));

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e1);
    ecs_table_t *this_var = ecs_iter_get_var_as_table(&it, this_var_id);
    test_assert(this_var != NULL);
    test_assert(this_var == t1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e2);
    this_var = ecs_iter_get_var_as_table(&it, this_var_id);
    test_assert(this_var != NULL);
    test_assert(this_var == t2);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_uint(it.entities[0], e3);
    test_uint(it.entities[1], e4);
    this_var = ecs_iter_get_var_as_table(&it, this_var_id);
    test_assert(this_var != NULL);
    test_assert(this_var == t3);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_iter_w_this_var_as_table_range() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_entity_t e2 = ecs_new(world, TagA);
    ecs_entity_t e3 = ecs_new(world, TagA);
    ecs_entity_t e4 = ecs_new(world, TagA);
    ecs_add(world, e2, TagB);
    ecs_add(world, e3, TagC);
    ecs_add(world, e4, TagC);

    ecs_table_t *t1 = ecs_get_table(world, e1);
    test_assert(t1 != NULL);

    ecs_table_t *t2 = ecs_get_table(world, e2);
    test_assert(t2 != NULL);
    test_assert(t2 != t1);

    ecs_table_t *t3 = ecs_get_table(world, e3);
    test_assert(t3 != NULL);
    test_assert(t3 != t1);
    test_assert(t3 != t2);
    test_assert(t3 == ecs_get_table(world, e4));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }}
    }));

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e1);
    ecs_table_range_t this_var = ecs_iter_get_var_as_range(&it, this_var_id);
    test_assert(this_var.table != NULL);
    test_assert(this_var.table == t1);
    test_assert(this_var.offset == 0);
    test_assert(this_var.count == 1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e2);
    this_var = ecs_iter_get_var_as_range(&it, this_var_id);
    test_assert(this_var.table != NULL);
    test_assert(this_var.table == t2);
    test_assert(this_var.offset == 0);
    test_assert(this_var.count == 1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_uint(it.entities[0], e3);
    test_uint(it.entities[1], e4);
    this_var = ecs_iter_get_var_as_range(&it, this_var_id);
    test_assert(this_var.table != NULL);
    test_assert(this_var.table == t3);
    test_assert(this_var.offset == 0);
    test_assert(this_var.count == 2);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_wo_this_var() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_entity_t e1 = ecs_new(world, TagA);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .id = TagA, .src.id = e1 }}
    }));

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id == -1); /* Filter has no This terms */

    /* Make sure it matches for good measure */
    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 0);
    test_int(it.sources[0], e1);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_set_this_to_table_1_term() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_entity_t e2 = ecs_new(world, TagA);
    ecs_entity_t e3 = ecs_new(world, TagA);
    ecs_entity_t e4 = ecs_new(world, TagA);
    ecs_add(world, e2, TagB);
    ecs_add(world, e3, TagC);
    ecs_add(world, e4, TagC);

    ecs_table_t *t1 = ecs_get_table(world, e1);
    test_assert(t1 != NULL);

    ecs_table_t *t2 = ecs_get_table(world, e2);
    test_assert(t2 != NULL);
    test_assert(t2 != t1);

    ecs_table_t *t3 = ecs_get_table(world, e3);
    test_assert(t3 != NULL);
    test_assert(t3 != t1);
    test_assert(t3 != t2);
    test_assert(t3 == ecs_get_table(world, e4));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }}
    }));

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t1);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e1);
    test_assert(!ecs_filter_next(&it));

    it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t2);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e2);
    test_assert(!ecs_filter_next(&it));

    it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t3);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_uint(it.entities[0], e3);
    test_uint(it.entities[1], e4);
    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_set_this_to_table_2_terms() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);
    ECS_TAG(world, TagC);
    ECS_TAG(world, TagD);

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_entity_t e2 = ecs_new(world, TagA);
    ecs_entity_t e3 = ecs_new(world, TagA);
    ecs_entity_t e4 = ecs_new(world, TagA);
    ecs_add(world, e1, TagB);
    ecs_add(world, e2, TagB);
    ecs_add(world, e3, TagB);
    ecs_add(world, e4, TagB);
    ecs_add(world, e2, TagC);
    ecs_add(world, e3, TagD);
    ecs_add(world, e4, TagD);

    ecs_table_t *t1 = ecs_get_table(world, e1);
    test_assert(t1 != NULL);

    ecs_table_t *t2 = ecs_get_table(world, e2);
    test_assert(t2 != NULL);
    test_assert(t2 != t1);

    ecs_table_t *t3 = ecs_get_table(world, e3);
    test_assert(t3 != NULL);
    test_assert(t3 != t1);
    test_assert(t3 != t2);
    test_assert(t3 == ecs_get_table(world, e4));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }, { TagB }}
    }));

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t1);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e1);
    test_assert(!ecs_filter_next(&it));

    it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t2);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e2);
    test_assert(!ecs_filter_next(&it));

    it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t3);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_uint(it.entities[0], e3);
    test_uint(it.entities[1], e4);
    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_set_this_to_table_1_wildcard() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Tag);
    ECS_TAG(world, Rel);
    ECS_TAG(world, ObjA);
    ECS_TAG(world, ObjB);
    ECS_TAG(world, ObjC);

    ecs_entity_t e1 = ecs_new(world, Tag);
    ecs_entity_t e2 = ecs_new(world, Tag);
    ecs_entity_t e3 = ecs_new(world, Tag);
    ecs_entity_t e4 = ecs_new(world, Tag);
    ecs_add_pair(world, e1, Rel, ObjA);
    ecs_add_pair(world, e2, Rel, ObjA);
    ecs_add_pair(world, e3, Rel, ObjA);
    ecs_add_pair(world, e4, Rel, ObjA);

    ecs_add_pair(world, e2, Rel, ObjB);
    ecs_add_pair(world, e3, Rel, ObjC);
    ecs_add_pair(world, e4, Rel, ObjC);

    ecs_table_t *t1 = ecs_get_table(world, e1);
    test_assert(t1 != NULL);

    ecs_table_t *t2 = ecs_get_table(world, e2);
    test_assert(t2 != NULL);
    test_assert(t2 != t1);

    ecs_table_t *t3 = ecs_get_table(world, e3);
    test_assert(t3 != NULL);
    test_assert(t3 != t1);
    test_assert(t3 != t2);
    test_assert(t3 == ecs_get_table(world, e4));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ Tag }, { ecs_pair(Rel, EcsWildcard) }}
    }));

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t1);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e1);
    test_uint(ecs_field_id(&it, 1), Tag);
    test_uint(ecs_field_id(&it, 2), ecs_pair(Rel, ObjA));
    test_assert(!ecs_filter_next(&it));

    it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t2);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e2);
    test_uint(ecs_field_id(&it, 1), Tag);
    test_uint(ecs_field_id(&it, 2), ecs_pair(Rel, ObjA));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e2);
    test_uint(ecs_field_id(&it, 1), Tag);
    test_uint(ecs_field_id(&it, 2), ecs_pair(Rel, ObjB));
    test_assert(!ecs_filter_next(&it));

    it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t3);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_uint(it.entities[0], e3);
    test_uint(it.entities[1], e4);
    test_uint(ecs_field_id(&it, 1), Tag);
    test_uint(ecs_field_id(&it, 2), ecs_pair(Rel, ObjA));

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 2);
    test_uint(it.entities[0], e3);
    test_uint(it.entities[1], e4);
    test_uint(ecs_field_id(&it, 1), Tag);
    test_uint(ecs_field_id(&it, 2), ecs_pair(Rel, ObjC));
    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_set_this_to_table_no_match_no_data() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e1 = ecs_new(world, TagB);

    ecs_table_t *t1 = ecs_get_table(world, e1);
    test_assert(t1 != NULL);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }}
    }));

    test_bool(f.flags & EcsFilterMatchThis, true);

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t1);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}


void Filter_set_this_to_table_no_match() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_new(world, TagA);

    ecs_entity_t e1 = ecs_new(world, TagB);
    ecs_table_t *t1 = ecs_get_table(world, e1);
    test_assert(t1 != NULL);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }}
    }));

    test_bool(f.flags & EcsFilterMatchThis, true);

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t1);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_set_this_to_table_2_terms_no_match() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_new(world, TagA);

    ecs_entity_t e1 = ecs_new(world, TagB);
    ecs_table_t *t1 = ecs_get_table(world, e1);
    test_assert(t1 != NULL);
    
    ecs_entity_t e2 = ecs_new(world, TagA);
    ecs_table_t *t2 = ecs_get_table(world, e2);
    test_assert(t2 != NULL);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }, { TagB }}
    }));

    test_bool(f.flags & EcsFilterMatchThis, true);

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t1);
    test_bool(false, ecs_filter_next(&it));

    it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t2);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_set_this_to_empty_table() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);
    ECS_TAG(world, TagB);

    ecs_entity_t e1 = ecs_new(world, TagA);
    ecs_add(world, e1, TagB);
    ecs_table_t *t1 = ecs_get_table(world, e1);
    ecs_remove(world, e1, TagB);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }}
    }));

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 0);
    test_assert(it.table == t1);
    test_uint(ecs_field_id(&it, 1), TagA);
    test_uint(ecs_field_size(&it, 1), 0);
    ecs_table_t* this_var = ecs_iter_get_var_as_table(&it, this_var_id);
    test_assert(this_var != NULL);
    test_assert(this_var == t1);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_set_this_to_empty_table_w_component() {
    ecs_world_t *world = ecs_mini();

    ECS_COMPONENT(world, Position);
    ECS_TAG(world, TagA);

    ecs_entity_t e1 = ecs_new(world, Position);
    ecs_add(world, e1, TagA);
    ecs_table_t *t1 = ecs_get_table(world, e1);
    ecs_remove(world, e1, TagA);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ ecs_id(Position) }}
    }));

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 0);
    test_assert(it.table == t1);
    test_uint(ecs_field_id(&it, 1), ecs_id(Position));
    test_uint(ecs_field_size(&it, 1), sizeof(Position));
    test_assert(ecs_field(&it, Position, 1) == NULL);
    ecs_table_t* this_var = ecs_iter_get_var_as_table(&it, this_var_id);
    test_assert(this_var != NULL);
    test_assert(this_var == t1);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_set_this_to_implicit_isa_superset_match() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_entity_t base = ecs_new(world, TagA);
    ecs_entity_t inst = ecs_new_w_pair(world, EcsIsA, base);
    ecs_table_t *t1 = ecs_get_table(world, inst);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ TagA }}
    }));

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], inst);
    test_assert(it.table == t1);
    test_uint(ecs_field_id(&it, 1), TagA);
    test_uint(ecs_field_size(&it, 1), 0);
    ecs_table_t* this_var = ecs_iter_get_var_as_table(&it, this_var_id);
    test_assert(this_var != NULL);
    test_assert(this_var == t1);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_set_this_to_self_isa_superset_match() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_entity_t base = ecs_new(world, TagA);
    ecs_entity_t inst = ecs_new_w_pair(world, EcsIsA, base);
    ecs_table_t *t1 = ecs_get_table(world, inst);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .id = TagA, .src.flags = EcsUp | EcsSelf }}
    }));

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], inst);
    test_assert(it.table == t1);
    test_uint(ecs_field_id(&it, 1), TagA);
    test_uint(ecs_field_size(&it, 1), 0);
    ecs_table_t* this_var = ecs_iter_get_var_as_table(&it, this_var_id);
    test_assert(this_var != NULL);
    test_assert(this_var == t1);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_set_this_to_isa_superset_match() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_entity_t base = ecs_new(world, TagA);
    ecs_entity_t inst = ecs_new_w_pair(world, EcsIsA, base);
    ecs_table_t *t1 = ecs_get_table(world, inst);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .id = TagA, .src.flags = EcsUp }}
    }));

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], inst);
    test_assert(it.table == t1);
    test_uint(ecs_field_id(&it, 1), TagA);
    test_uint(ecs_field_size(&it, 1), 0);
    ecs_table_t* this_var = ecs_iter_get_var_as_table(&it, this_var_id);
    test_assert(this_var != NULL);
    test_assert(this_var == t1);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_set_this_to_childof_superset_match() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_entity_t base = ecs_new(world, TagA);
    ecs_entity_t inst = ecs_new_w_pair(world, EcsChildOf, base);
    ecs_table_t *t1 = ecs_get_table(world, inst);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .id = TagA, 
            .src.flags = EcsUp,
            .src.trav = EcsChildOf
        }}
    }));

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], inst);
    test_assert(it.table == t1);
    test_uint(ecs_field_id(&it, 1), TagA);
    test_uint(ecs_field_size(&it, 1), 0);
    ecs_table_t* this_var = ecs_iter_get_var_as_table(&it, this_var_id);
    test_assert(this_var != NULL);
    test_assert(this_var == t1);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_set_this_to_superset_w_self_filter_no_match() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_entity_t base = ecs_new(world, TagA);
    ecs_entity_t inst = ecs_new_w_pair(world, EcsIsA, base);
    ecs_table_t *t1 = ecs_get_table(world, inst);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .id = TagA, .src.flags = EcsSelf }}
    }));

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t1);

    test_assert(!ecs_filter_next(&it));

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_set_this_to_isa_cascade() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_entity_t base = ecs_new(world, TagA);
    ecs_entity_t inst = ecs_new_w_pair(world, EcsIsA, base);
    ecs_table_t *t1 = ecs_get_table(world, inst);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ .id = TagA, .src.flags = EcsCascade }}
    }));

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], inst);
    test_assert(it.table == t1);
    test_uint(ecs_field_id(&it, 1), TagA);
    test_uint(ecs_field_size(&it, 1), 0);
    ecs_table_t* this_var = ecs_iter_get_var_as_table(&it, this_var_id);
    test_assert(this_var != NULL);
    test_assert(this_var == t1);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_set_this_to_childof_cascade() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, TagA);

    ecs_entity_t base = ecs_new(world, TagA);
    ecs_entity_t inst = ecs_new_w_pair(world, EcsChildOf, base);
    ecs_table_t *t1 = ecs_get_table(world, inst);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{ 
            .id = TagA, 
            .src.flags = EcsCascade,
            .src.trav = EcsChildOf
        }}
    }));

    int this_var_id = ecs_filter_find_this_var(&f);
    test_assert(this_var_id != -1);

    ecs_iter_t it = ecs_filter_iter(world, &f);
    ecs_iter_set_var_as_table(&it, this_var_id, t1);

    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], inst);
    test_assert(it.table == t1);
    test_uint(ecs_field_id(&it, 1), TagA);
    test_uint(ecs_field_size(&it, 1), 0);
    ecs_table_t* this_var = ecs_iter_get_var_as_table(&it, this_var_id);
    test_assert(this_var != NULL);
    test_assert(this_var == t1);

    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_set_this_w_wildcard_2_matches() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Rel);
    ECS_TAG(world, ObjA);
    ECS_TAG(world, ObjB);
    ECS_TAG(world, ObjC);

    ecs_filter_t *f = ecs_filter(world, {
        .terms[0] = { ecs_pair(Rel, EcsWildcard) }
    });

    ecs_entity_t e1 = ecs_new_w_pair(world, Rel, ObjA);
    ecs_entity_t e2 = ecs_new_w_pair(world, Rel, ObjB);
    ecs_add_pair(world, e1, Rel, ObjC);
    ecs_add_pair(world, e2, Rel, ObjC);

    ecs_iter_t it = ecs_filter_iter(world, f);
    ecs_iter_set_var(&it, 0, e1);

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(ecs_pair(Rel, ObjA), ecs_field_id(&it, 1));

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(ecs_pair(Rel, ObjC), ecs_field_id(&it, 1));
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_set_this_to_entity_superset_self_has_component() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);

    ecs_entity_t parent = ecs_set(world, 0, Position, {1, 2});

    ecs_entity_t e1 = ecs_new_id(world);
    ecs_add_pair(world, e1, EcsChildOf, parent);
    ecs_set(world, e1, Position, {10, 20});

    ecs_filter_t *f = ecs_filter(world, {
      .terms = {{ ecs_id(Position), .src.flags = EcsUp, .src.trav = EcsChildOf }}
    });

    ecs_iter_t it = ecs_filter_iter(world, f);
    ecs_iter_set_var(&it, 0, e1);

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);

    Position *p = ecs_field(&it, Position, 1);
    test_int(p->x, 1);
    test_int(p->y, 2);
    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_set_this_to_1_entity_in_table() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);

    ecs_filter_t *f = ecs_filter(world, {
        .terms[0].id = ecs_id(Position)
    });

    ecs_entity_t e1 = ecs_set(world, 0, Position, {10, 20});
    ecs_entity_t e2 = ecs_set(world, 0, Position, {20, 30});

    {
        ecs_iter_t it = ecs_filter_iter(world, f);
        ecs_iter_set_var(&it, 0, e1);
        test_bool(true, ecs_filter_next(&it));
        test_int(it.count, 1);
        test_uint(it.entities[0], e1);
        Position *p = ecs_field(&it, Position, 1);
        test_assert(p != NULL);
        test_int(p->x, 10);
        test_int(p->y, 20);
        test_bool(false, ecs_filter_next(&it));
    }

    {
        ecs_iter_t it = ecs_filter_iter(world, f);
        ecs_iter_set_var(&it, 0, e2);
        test_bool(true, ecs_filter_next(&it));
        test_int(it.count, 1);
        test_uint(it.entities[0], e2);
        Position *p = ecs_field(&it, Position, 1);
        test_assert(p != NULL);
        test_int(p->x, 20);
        test_int(p->y, 30);
        test_bool(false, ecs_filter_next(&it));
    }

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_oneof() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Parent);
    ECS_ENTITY(world, Rel, (OneOf, Parent));
    ECS_ENTITY(world, ObjA, (ChildOf, Parent));
    ECS_ENTITY(world, ObjB, (ChildOf, Parent));

    ecs_entity_t e1 = ecs_new_w_pair(world, Rel, ObjA);
    test_assert( ecs_has_pair(world, e1, Rel, ObjA));
    ecs_entity_t e2 = ecs_new_w_pair(world, Rel, ObjB);
    test_assert( ecs_has_pair(world, e2, Rel, ObjB));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{
            .id = ecs_pair(Rel, ObjB)
        }}
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e2, it.entities[0]);
    test_uint(ecs_pair(Rel, ObjB), ecs_field_id(&it, 1));

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_oneof_expr() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Parent);
    ECS_ENTITY(world, Rel, (OneOf, Parent));
    ECS_ENTITY(world, ObjA, (ChildOf, Parent));
    ECS_ENTITY(world, ObjB, (ChildOf, Parent));

    ecs_entity_t e1 = ecs_new_w_pair(world, Rel, ObjA);
    test_assert( ecs_has_pair(world, e1, Rel, ObjA));
    ecs_entity_t e2 = ecs_new_w_pair(world, Rel, ObjB);
    test_assert( ecs_has_pair(world, e2, Rel, ObjB));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "(Rel, ObjB)"
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e2, it.entities[0]);
    test_uint(ecs_pair(Rel, ObjB), ecs_field_id(&it, 1));

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_oneof_w_mismatching_obj() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Parent);
    ECS_ENTITY(world, Rel, (OneOf, Parent));
    ECS_ENTITY(world, ObjA, (ChildOf, Parent));
    ECS_ENTITY(world, ObjB, (ChildOf, Parent));
    ECS_TAG(world, ObjC)

    ecs_entity_t e1 = ecs_new_w_pair(world, Rel, ObjA);
    test_assert( ecs_has_pair(world, e1, Rel, ObjA));
    ecs_entity_t e2 = ecs_new_w_pair(world, Rel, ObjB);
    test_assert( ecs_has_pair(world, e2, Rel, ObjB));

    ecs_log_set_level(-4);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL == ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{
            .id = ecs_pair(Rel, ObjC)
        }}
    }));

    ecs_fini(world);
}

void Filter_oneof_w_mismatching_obj_expr() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Parent);
    ECS_ENTITY(world, Rel, (OneOf, Parent));
    ECS_ENTITY(world, ObjA, (ChildOf, Parent));
    ECS_ENTITY(world, ObjB, (ChildOf, Parent));
    ECS_TAG(world, ObjC)

    ecs_entity_t e1 = ecs_new_w_pair(world, Rel, ObjA);
    test_assert( ecs_has_pair(world, e1, Rel, ObjA));
    ecs_entity_t e2 = ecs_new_w_pair(world, Rel, ObjB);
    test_assert( ecs_has_pair(world, e2, Rel, ObjB));

    ecs_log_set_level(-4);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL == ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .expr = "(Rel, ObjC)"
    }));

    ecs_fini(world);
}

void Filter_oneof_wildcard() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Parent);
    ECS_ENTITY(world, Rel, (OneOf, Parent));
    ECS_ENTITY(world, ObjA, (ChildOf, Parent));
    ECS_ENTITY(world, ObjB, (ChildOf, Parent));

    ecs_entity_t e1 = ecs_new_w_pair(world, Rel, ObjA);
    test_assert( ecs_has_pair(world, e1, Rel, ObjA));
    ecs_entity_t e2 = ecs_new_w_pair(world, Rel, ObjB);
    test_assert( ecs_has_pair(world, e2, Rel, ObjB));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{
            .id = ecs_pair(Rel, EcsWildcard)
        }}
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(ecs_pair(Rel, ObjA), ecs_field_id(&it, 1));

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e2, it.entities[0]);
    test_uint(ecs_pair(Rel, ObjB), ecs_field_id(&it, 1));

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_oneof_any() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Parent);
    ECS_ENTITY(world, Rel, (OneOf, Parent));
    ECS_ENTITY(world, ObjA, (ChildOf, Parent));
    ECS_ENTITY(world, ObjB, (ChildOf, Parent));

    ecs_entity_t e1 = ecs_new_w_pair(world, Rel, ObjA);
    test_assert( ecs_has_pair(world, e1, Rel, ObjA));
    ecs_entity_t e2 = ecs_new_w_pair(world, Rel, ObjB);
    test_assert( ecs_has_pair(world, e2, Rel, ObjB));

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{
            .id = ecs_pair(Rel, EcsAny)
        }}
    }));

    ecs_iter_t it = ecs_filter_iter(world, &f);
    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e1, it.entities[0]);
    test_uint(ecs_pair(Rel, ObjA), ecs_field_id(&it, 1));

    test_bool(true, ecs_filter_next(&it));
    test_int(1, it.count);
    test_uint(e2, it.entities[0]);
    test_uint(ecs_pair(Rel, ObjB), ecs_field_id(&it, 1));

    test_bool(false, ecs_filter_next(&it));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_flag_match_only_this() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Foo);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{
            .id = Foo
        }}
    }));

    test_assert(f.flags & EcsFilterMatchOnlyThis);

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_flag_match_only_this_w_ref() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Foo);
    ECS_TAG(world, Bar);
    ECS_TAG(world, Src);

    ecs_filter_t f = ECS_FILTER_INIT;
    test_assert(NULL != ecs_filter_init(world, &(ecs_filter_desc_t){
        .storage = &f,
        .terms = {{
            .id = Foo
        }, {
            .id = Bar,
            .src.id = Src
        }}
    }));

    test_assert(!(f.flags & EcsFilterMatchOnlyThis));

    ecs_filter_fini(&f);

    ecs_fini(world);
}

void Filter_filter_w_alloc() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Foo);

    ecs_filter_t *f = ecs_filter_init(world, &(ecs_filter_desc_t){
        .terms = {{
            .id = Foo
        }}
    });
    
    test_assert(f != NULL);

    ecs_entity_t e = ecs_new(world, Foo);

    ecs_iter_t it = ecs_filter_iter(world, f);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e);
    test_uint(it.ids[0], ecs_field_id(&it, 1));
    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}

void Filter_filter_w_short_notation() {
    ecs_world_t *world = ecs_mini();

    ECS_TAG(world, Foo);

    ecs_filter_t *f = ecs_filter(world, {
        .terms = {{
            .id = Foo
        }}
    });

    test_assert(f != NULL);

    ecs_entity_t e = ecs_new(world, Foo);

    ecs_iter_t it = ecs_filter_iter(world, f);
    test_assert(ecs_filter_next(&it));
    test_int(it.count, 1);
    test_uint(it.entities[0], e);
    test_uint(it.ids[0], ecs_field_id(&it, 1));
    test_assert(!ecs_filter_next(&it));

    ecs_filter_fini(f);

    ecs_fini(world);
}
