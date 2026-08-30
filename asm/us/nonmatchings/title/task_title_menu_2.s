.syntax unified
	.align 2, 0
	.global task_title_menu_2
	.thumb
	.thumb_func
	.type task_title_menu_2, %function
task_title_menu_2: @ 080D6DB0
	push {r4, lr}
	adds r4, r0, #0x0
	adds r0, #0x2C
	bl func_08005A64
	str r0, [r4, #0x20]
	ldr r1, _080D6DF4 @ =0x09EF6620
	ldr r2, [r4, #0x44]
	movs r3, #0x00
	ldsh r0, [r2, r3]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x24]
	ldr r1, _080D6DF8 @ =0x09EF663C
	movs r3, #0x00
	ldsh r0, [r2, r3]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x28]
	ldr r0, _080D6DFC @ =0x02039BB0
	ldr r1, [r0, #0x08]
	movs r0, #0x80
	lsls r0, r0, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _080D6E00
	adds r1, r4, #0x0
	adds r1, #0x60
	movs r0, #0x78
	strh r0, [r1, #0x00]
	b _080D6E06
	.byte 0x00, 0x00
_080D6DF4: .4byte 0x09EF6620
_080D6DF8: .4byte 0x09EF663C
_080D6DFC: .4byte 0x02039BB0
_080D6E00:
	adds r0, r4, #0x0
	adds r0, #0x60
	strh r1, [r0, #0x00]
_080D6E06:
	ldr r0, [r4, #0x5C]
	cmp r0, #0x00
	bne _080D6E14
	adds r0, r4, #0x0
	bl func_080D6A64
	b _080D6E32
_080D6E14:
	cmp r0, #0x03
	bne _080D6E20
	adds r0, r4, #0x0
	bl func_080D6B7C
	b _080D6E32
_080D6E20:
	cmp r0, #0x04
	bne _080D6E2C
	adds r0, r4, #0x0
	bl func_080D6C54
	b _080D6E32
_080D6E2C:
	adds r0, r4, #0x0
	bl func_080D6D2C
_080D6E32:
	adds r0, r4, #0x0
	adds r0, #0x48
	bl func_08000EE0
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
