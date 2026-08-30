.syntax unified
	.align 2, 0
	.global func_081185CC
	.thumb
	.thumb_func
	.type func_081185CC, %function
func_081185CC: @ 081185CC
	push {r7, lr}
	add sp, #-0x008
	mov r7, sp
	ldr r0, _081185FC @ =0x04000208
	movs r1, #0x00
	strh r1, [r0, #0x00]
	adds r0, r7, #0x4
	ldr r1, _08118600 @ =0x04000006
	ldrh r2, [r1, #0x00]
	strh r2, [r0, #0x00]
	adds r0, r7, #0x4
	ldrh r1, [r0, #0x00]
	cmp r1, #0x9F
	bls _08118608
	ldr r0, _08118604 @ =0x0203C7D0
	adds r1, r7, #0x4
	ldrh r2, [r1, #0x00]
	adds r1, r2, #0x0
	subs r1, #0xE4
	ldr r0, [r0, #0x10]
	adds r1, r0, r1
	str r1, [r7, #0x00]
	b _08118614
	.byte 0x00, 0x00
_081185FC: .4byte 0x04000208
_08118600: .4byte 0x04000006
_08118604: .4byte 0x0203C7D0
_08118608:
	ldr r0, _08118620 @ =0x0203C7D0
	adds r1, r7, #0x4
	ldrh r2, [r1, #0x00]
	ldr r0, [r0, #0x10]
	adds r1, r0, r2
	str r1, [r7, #0x00]
_08118614:
	ldr r0, _08118624 @ =0x04000208
	movs r1, #0x01
	strh r1, [r0, #0x00]
	ldr r1, [r7, #0x00]
	adds r0, r1, #0x0
	b _08118628
_08118620: .4byte 0x0203C7D0
_08118624: .4byte 0x04000208
_08118628:
	add sp, #0x008
	pop {r7}
	pop {r1}
	bx r1
.syntax divided
