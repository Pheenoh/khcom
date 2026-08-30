.syntax unified
	.align 2, 0
	.global task_hum_axcel_ptc_0
	.thumb
	.thumb_func
	.type task_hum_axcel_ptc_0, %function
task_hum_axcel_ptc_0: @ 08054208
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x24]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x28]
	ldr r0, [r1, #0x08]
	str r0, [r4, #0x2C]
	ldr r0, _0805425C @ =0x08BF73C6
	movs r1, #0xC0
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _08054260 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	adds r4, #0x0C
	ldr r1, _08054264 @ =0x09EE1FC0
	ldr r2, _08054268 @ =0x09EE1F90
	adds r0, r4, #0x0
	bl func_08005968
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x03
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	beq _08054278
	cmp r0, #0x01
	bgt _0805426C
	cmp r0, #0x00
	beq _08054272
	b _0805428E
	.byte 0x00, 0x00
_0805425C: .4byte 0x08BF73C6
_08054260: .4byte 0x08F69BA4
_08054264: .4byte 0x09EE1FC0
_08054268: .4byte 0x09EE1F90
_0805426C:
	cmp r0, #0x02
	beq _08054284
	b _0805428E
_08054272:
	adds r0, r4, #0x0
	movs r1, #0x00
	b _0805427C
_08054278:
	adds r0, r4, #0x0
	movs r1, #0x01
_0805427C:
	movs r2, #0x00
	bl func_080059A4
	b _0805428E
_08054284:
	adds r0, r4, #0x0
	movs r1, #0x02
	movs r2, #0x00
	bl func_080059A4
_0805428E:
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
