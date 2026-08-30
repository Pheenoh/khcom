.syntax unified
	.align 2, 0
	.global task_poo_tiggerroo_0
	.thumb
	.thumb_func
	.type task_poo_tiggerroo_0, %function
task_poo_tiggerroo_0: @ 080CED58
	push {r4, r5, r6, lr}
	add sp, #-0x00C
	adds r6, r0, #0x0
	adds r1, r6, #0x0
	adds r1, #0xC0
	movs r0, #0x02
	str r0, [r1, #0x00]
	adds r2, r6, #0x0
	adds r2, #0xB8
	movs r1, #0x00
	movs r0, #0x2D
	strb r0, [r2, #0x00]
	adds r0, r6, #0x0
	adds r0, #0xD1
	strb r1, [r0, #0x00]
	str r1, [r6, #0x04]
	str r1, [r6, #0x00]
	ldr r4, _080CEDE8 @ =0x09EF5EF8
	adds r0, r4, #0x0
	movs r1, #0x12
	bl func_08003524
	adds r1, r6, #0x0
	adds r1, #0xD2
	strh r0, [r1, #0x00]
	adds r5, r6, #0x0
	adds r5, #0x0C
	ldr r1, _080CEDEC @ =0x09EF5FA0
	adds r0, r5, #0x0
	adds r2, r4, #0x0
	bl func_08005968
	movs r0, #0x04
	strh r0, [r6, #0x26]
	adds r0, r6, #0x0
	movs r1, #0x00
	bl func_080CE710
	adds r0, r6, #0x0
	bl func_080CE8B4
	adds r0, r5, #0x0
	bl func_08005AFC
	str r0, [r6, #0x08]
	adds r4, r6, #0x0
	adds r4, #0x94
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08000E64
	adds r0, r6, #0x0
	adds r0, #0x28
	str r0, [sp, #0x000]
	adds r0, #0xA0
	str r0, [sp, #0x004]
	ldr r1, _080CEDF0 @ =0x09EF4940
	adds r0, r4, #0x0
	mov r2, sp
	bl func_08000E14
	adds r0, r6, #0x0
	adds r0, #0x38
	ldr r1, [r6, #0x28]
	ldr r2, [r6, #0x2C]
	ldr r3, [r6, #0x30]
	bl func_08012324
	add sp, #0x00C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080CEDE8: .4byte 0x09EF5EF8
_080CEDEC: .4byte 0x09EF5FA0
_080CEDF0: .4byte 0x09EF4940
.syntax divided
