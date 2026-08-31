.syntax unified
	.align 2, 0
	.global func_08012798
	.thumb
	.thumb_func
	.type func_08012798, %function
func_08012798: @ 08012798
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	ldr r4, _080127D0 @ =0x02034928
	movs r0, #0x50
	bl EwramAlloc
	str r0, [r4, #0x00]
	movs r4, #0x0A
_080127AE:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	adds r4, #0x01
	cmp r4, #0x0F
	ble _080127AE
	cmp r5, #0x00
	bne _080127D4
	movs r1, #0xC0
	lsls r1, r1, #0x08
	adds r0, r6, #0x0
	movs r2, #0x00
	bl func_080065FC
	b _080127E0
_080127D0: .4byte 0x02034928
_080127D4:
	movs r1, #0x80
	lsls r1, r1, #0x08
	adds r0, r6, #0x0
	movs r2, #0x80
	bl func_080065FC
_080127E0:
	adds r0, r6, #0x0
	movs r1, #0x10
	movs r2, #0x10
	bl func_080057A0
	ldr r4, _0801280C @ =0x02034928
	ldr r0, [r4, #0x00]
	movs r5, #0x00
	str r5, [r0, #0x04]
	adds r0, #0x38
	movs r1, #0xFF
	strb r1, [r0, #0x00]
	ldr r0, [r4, #0x00]
	str r6, [r0, #0x00]
	bl func_08012674
	ldr r0, [r4, #0x00]
	strh r5, [r0, #0x34]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801280C: .4byte 0x02034928
.syntax divided
