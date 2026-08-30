.syntax unified
	.align 2, 0
	.global task_bos_boogie_explosiondice_1
	.thumb
	.thumb_func
	.type task_bos_boogie_explosiondice_1, %function
task_bos_boogie_explosiondice_1: @ 080DA5F8
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r5, #0x0
	adds r4, #0x40
	bl func_080DA4DC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080DA670
	ldr r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080DA616
	cmp r0, #0x02
	beq _080DA644
	b _080DA652
_080DA616:
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldr r0, [r1, #0x00]
	adds r0, #0x33
	str r0, [r1, #0x00]
	ldr r1, [r4, #0x0C]
	adds r2, r1, r0
	str r2, [r4, #0x0C]
	ldr r0, _080DA640 @ =0xFFFFE000
	cmp r2, r0
	ble _080DA652
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x08]
	adds r1, r1, r2
	movs r2, #0x00
	bl func_08014020
	movs r0, #0x00
	b _080DA672
	.byte 0x00, 0x00
_080DA640: .4byte 0xFFFFE000
_080DA644:
	bl func_080128EC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080DA652
	movs r0, #0x00
	b _080DA672
_080DA652:
	adds r0, r5, #0x0
	adds r0, #0x14
	bl func_08005A64
	adds r0, r4, #0x0
	adds r0, #0x40
	ldr r1, [r4, #0x04]
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x0C]
	bl func_08012324
	adds r0, r5, #0x0
	adds r0, #0x2C
	bl func_08000EA4
_080DA670:
	movs r0, #0x01
_080DA672:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
