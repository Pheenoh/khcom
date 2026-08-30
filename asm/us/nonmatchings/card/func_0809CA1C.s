.syntax unified
	.align 2, 0
	.global func_0809CA1C
	.thumb
	.thumb_func
	.type func_0809CA1C, %function
func_0809CA1C: @ 0809CA1C
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r4, #0x0
	adds r5, #0x54
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	bne _0809CAB0
	ldr r0, [r4, #0x04]
	ldr r0, [r0, #0x0C]
	movs r1, #0xA0
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r4, #0x0C]
	ldr r0, _0809CAB8 @ =0x09611AB8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x28]
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x04]
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r4, #0x08]
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x08]
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x24]
	ldr r0, _0809CABC @ =0x0905EAE8
	movs r1, #0xF0
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x10]
	ldr r0, _0809CAC0 @ =0x0905ED36
	movs r1, #0xA0
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x1C]
	ldr r0, _0809CAC4 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x20]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, [r4, #0x28]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, [r4, #0x24]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	movs r0, #0x01
	strb r0, [r5, #0x00]
_0809CAB0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0809CAB8: .4byte 0x09611AB8
_0809CABC: .4byte 0x0905EAE8
_0809CAC0: .4byte 0x0905ED36
_0809CAC4: .4byte 0x08F69BA4
.syntax divided
