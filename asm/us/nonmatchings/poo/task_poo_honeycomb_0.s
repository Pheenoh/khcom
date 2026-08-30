.syntax unified
	.align 2, 0
	.global task_poo_honeycomb_0
	.thumb
	.thumb_func
	.type task_poo_honeycomb_0, %function
task_poo_honeycomb_0: @ 080CFA84
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	ldr r0, _080CFAD4 @ =0x0008DE00
	str r0, [r6, #0x24]
	ldr r0, _080CFAD8 @ =0x00046600
	str r0, [r6, #0x28]
	ldr r0, _080CFADC @ =0xFFFFF600
	str r0, [r6, #0x2C]
	movs r4, #0x00
	str r4, [r6, #0x30]
	ldr r0, _080CFAE0 @ =0x09EF5FF0
	movs r1, #0x01
	bl func_08003524
	movs r5, #0x00
	strh r0, [r6, #0x34]
	str r4, [r6, #0x04]
	ldr r0, _080CFAE4 @ =0x097567FC
	str r0, [r6, #0x08]
	adds r0, r6, #0x0
	adds r0, #0x38
	ldr r1, [r6, #0x24]
	ldr r2, [r6, #0x28]
	movs r3, #0x00
	bl func_08012324
	adds r0, r6, #0x0
	adds r0, #0x9C
	strb r5, [r0, #0x00]
	ldr r0, _080CFAE8 @ =0x02034E1C
	str r4, [r0, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x98
	str r4, [r0, #0x00]
	subs r0, #0x02
	strh r4, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CFAD4: .4byte 0x0008DE00
_080CFAD8: .4byte 0x00046600
_080CFADC: .4byte 0xFFFFF600
_080CFAE0: .4byte 0x09EF5FF0
_080CFAE4: .4byte 0x097567FC
_080CFAE8: .4byte 0x02034E1C
.syntax divided
