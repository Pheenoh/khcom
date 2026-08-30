.syntax unified
	.align 2, 0
	.global task_poo_wagonwheel_1
	.thumb
	.thumb_func
	.type task_poo_wagonwheel_1, %function
task_poo_wagonwheel_1: @ 080D0770
	push {r4, lr}
	adds r4, r0, #0x0
	ldrh r0, [r4, #0x36]
	cmp r0, #0x02
	bne _080D0796
	movs r0, #0x06
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D0796
	movs r0, #0x03
	strh r0, [r4, #0x36]
	adds r0, r4, #0x0
	adds r0, #0x0C
	movs r1, #0x03
	movs r2, #0x01
	bl func_080059A4
_080D0796:
	ldrh r0, [r4, #0x36]
	cmp r0, #0x03
	bne _080D07CE
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl func_08005A64
	str r0, [r4, #0x08]
	ldr r1, [r4, #0x38]
	ldr r0, _080D07E4 @ =0x000004FF
	cmp r1, r0
	bgt _080D07B2
	adds r0, r1, #0x6
	str r0, [r4, #0x38]
_080D07B2:
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x38]
	adds r0, r0, r1
	str r0, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r0, r0, r1
	str r0, [r4, #0x24]
	ldr r1, [r4, #0x3C]
	movs r2, #0x90
	lsls r2, r2, #0x07
	adds r1, r1, r2
	cmp r0, r1
	ble _080D07CE
	str r1, [r4, #0x24]
_080D07CE:
	adds r0, r4, #0x0
	adds r0, #0x40
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D07E8
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	bne _080D07E8
	movs r0, #0x00
	b _080D07EA
	.byte 0x00, 0x00
_080D07E4: .4byte 0x000004FF
_080D07E8:
	movs r0, #0x01
_080D07EA:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
