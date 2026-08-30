.syntax unified
	.align 2, 0
	.global task_poo_zzz_0
	.thumb
	.thumb_func
	.type task_poo_zzz_0, %function
task_poo_zzz_0: @ 080D1EA8
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r4, r1, #0x0
	ldr r0, _080D1EEC @ =0x0203C3EC
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x24]
	movs r0, #0x80
	lsls r0, r0, #0x01
	ldr r1, _080D1EF0 @ =0x097257D8
	bl func_080028F8
	str r0, [r6, #0x00]
	ldr r0, _080D1EF4 @ =0x09849A98
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x04]
	adds r5, r6, #0x0
	adds r5, #0x0C
	ldr r1, _080D1EF8 @ =0x09EF5904
	ldr r2, _080D1EFC @ =0x09EF5844
	adds r0, r5, #0x0
	bl func_08005968
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080D1F00
	adds r0, r5, #0x0
	movs r1, #0x08
	movs r2, #0x01
	bl func_080059A4
	b _080D1F0A
	.byte 0x00, 0x00
_080D1EEC: .4byte 0x0203C3EC
_080D1EF0: .4byte 0x097257D8
_080D1EF4: .4byte 0x09849A98
_080D1EF8: .4byte 0x09EF5904
_080D1EFC: .4byte 0x09EF5844
_080D1F00:
	adds r0, r5, #0x0
	movs r1, #0x07
	movs r2, #0x01
	bl func_080059A4
_080D1F0A:
	adds r0, r6, #0x0
	adds r0, #0x0C
	bl func_08005AFC
	str r0, [r6, #0x08]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
