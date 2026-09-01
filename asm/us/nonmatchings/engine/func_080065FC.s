.syntax unified
	.align 2, 0
	.global func_080065FC
	.thumb
	.thumb_func
	.type func_080065FC, %function
func_080065FC: @ 080065FC
	push {r4, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	lsls r2, r2, #0x10
	ldr r0, _08006648 @ =0x02034048
	str r4, [r0, #0x00]
	ldr r0, _0800664C @ =0x02034040
	movs r1, #0x00
	str r1, [r0, #0x00]
	ldr r0, _08006650 @ =0x02034050
	strh r1, [r0, #0x00]
	ldr r0, _08006654 @ =0x02034052
	strh r1, [r0, #0x00]
	ldr r0, _08006658 @ =0x02034054
	movs r1, #0x01
	strb r1, [r0, #0x00]
	cmp r2, #0x00
	bne _08006684
	ldr r1, _0800665C @ =0x02034058
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x07
	cmp r3, r0
	beq _08006660
	cmp r3, r0
	ble _08006678
	movs r0, #0x80
	lsls r0, r0, #0x08
	cmp r3, r0
	beq _08006660
	movs r0, #0xC0
	lsls r0, r0, #0x08
	cmp r3, r0
	beq _0800666C
	b _08006678
	.byte 0x00, 0x00
_08006648: .4byte 0x02034048
_0800664C: .4byte 0x02034040
_08006650: .4byte 0x02034050
_08006654: .4byte 0x02034052
_08006658: .4byte 0x02034054
_0800665C: .4byte 0x02034058
_08006660:
	ldr r1, _08006668 @ =0x02034056
	movs r2, #0x80
	lsls r2, r2, #0x05
	b _080066D6
_08006668: .4byte 0x02034056
_0800666C:
	ldr r1, _08006674 @ =0x02034056
	movs r2, #0x80
	lsls r2, r2, #0x06
	b _080066D6
_08006674: .4byte 0x02034056
_08006678:
	ldr r1, _08006680 @ =0x02034056
	movs r2, #0x80
	lsls r2, r2, #0x04
	b _080066D6
_08006680: .4byte 0x02034056
_08006684:
	ldr r0, _080066A8 @ =0x02034058
	strb r1, [r0, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x07
	cmp r3, r1
	beq _080066AC
	cmp r3, r1
	ble _080066D0
	movs r0, #0x80
	lsls r0, r0, #0x08
	cmp r3, r0
	beq _080066B8
	movs r0, #0xC0
	lsls r0, r0, #0x08
	cmp r3, r0
	beq _080066C4
	b _080066D0
	.byte 0x00, 0x00
_080066A8: .4byte 0x02034058
_080066AC:
	ldr r1, _080066B4 @ =0x02034056
	movs r2, #0x80
	lsls r2, r2, #0x03
	b _080066D6
_080066B4: .4byte 0x02034056
_080066B8:
	ldr r1, _080066C0 @ =0x02034056
	movs r2, #0x80
	lsls r2, r2, #0x05
	b _080066D6
_080066C0: .4byte 0x02034056
_080066C4:
	ldr r0, _080066CC @ =0x02034056
	strh r1, [r0, #0x00]
	b _080066DA
	.byte 0x00, 0x00
_080066CC: .4byte 0x02034056
_080066D0:
	ldr r1, _080066F0 @ =0x02034056
	movs r2, #0x80
	lsls r2, r2, #0x01
_080066D6:
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
_080066DA:
	adds r0, r4, #0x0
	adds r1, r3, #0x0
	bl SetBgSize
	adds r0, r4, #0x0
	bl DisableBg
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080066F0: .4byte 0x02034056
.syntax divided
