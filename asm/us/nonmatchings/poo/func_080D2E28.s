.syntax unified
	.align 2, 0
	.global func_080D2E28
	.thumb
	.thumb_func
	.type func_080D2E28, %function
func_080D2E28: @ 080D2E28
	push {r4, lr}
	adds r2, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _080D2E60 @ =0x0203C4B4
	ldr r3, [r4, #0x00]
	ldrh r0, [r3, #0x30]
	cmp r0, #0x05
	bhi _080D2E64
	lsls r0, r0, #0x03
	adds r0, r3, r0
	str r2, [r0, #0x00]
	ldrh r0, [r3, #0x30]
	lsls r0, r0, #0x03
	adds r0, r3, r0
	strh r1, [r0, #0x04]
	ldrh r0, [r3, #0x30]
	lsls r0, r0, #0x03
	adds r0, r3, r0
	movs r1, #0x01
	strb r1, [r0, #0x06]
	ldr r2, [r4, #0x00]
	ldrh r0, [r2, #0x30]
	adds r1, r0, #0x1
	strh r1, [r2, #0x30]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _080D2E66
_080D2E60: .4byte 0x0203C4B4
_080D2E64:
	ldr r0, _080D2E6C @ =0x0000FFFF
_080D2E66:
	pop {r4}
	pop {r1}
	bx r1
_080D2E6C: .4byte 0x0000FFFF
.syntax divided
