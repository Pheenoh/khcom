.syntax unified
	.align 2, 0
	.global func_08102984
	.thumb
	.thumb_func
	.type func_08102984, %function
func_08102984: @ 08102984
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	add r2, sp, #0x010
	movs r1, #0x00
	strh r1, [r2, #0x00]
	ldr r2, _08102A70 @ =0x040000D4
	add r1, sp, #0x010
	str r1, [r2, #0x00]
	ldr r1, _08102A74 @ =0x02035C00
	ldr r1, [r1, #0x00]
	str r1, [r2, #0x04]
	ldr r1, _08102A78 @ =0x81000280
	str r1, [r2, #0x08]
	ldr r1, [r2, #0x08]
	movs r6, #0x00
	ldr r2, _08102A7C @ =0x02035B18
	mov r10, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	lsls r1, r0, #0x01
	movs r5, #0x00
	movs r3, #0xC0
	mov r9, r3
	ldr r0, _08102A80 @ =0x02035B08
	adds r1, r1, r0
	str r1, [sp, #0x014]
_081029C2:
	lsls r1, r6, #0x02
	mov r4, r8
	lsls r0, r4, #0x04
	adds r4, r1, r0
	mov r7, r10
	adds r0, r4, r7
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	blt _08102A44
	movs r0, #0x02
	bl GetBgCharBase
	adds r2, r0, #0x0
	add r2, r9
	ldr r3, _08102A84 @ =0x02035B1A
	adds r0, r4, r3
	movs r4, #0x00
	ldsh r1, [r0, r4]
	lsls r1, r1, #0x01
	ldr r7, [sp, #0x014]
	movs r3, #0x00
	ldsh r0, [r7, r3]
	lsls r0, r0, #0x03
	adds r1, r1, r0
	ldr r4, _08102A88 @ =0x09993760
	adds r1, r1, r4
	movs r7, #0x00
	ldsh r0, [r1, r7]
	movs r1, #0x03
	str r1, [sp, #0x000]
	ldr r1, _08102A8C @ =0x09A18EBC
	movs r3, #0x40
	bl func_08101588
	ldr r4, _08102A90 @ =0x099931E4
	ldr r0, [sp, #0x014]
	movs r2, #0x00
	ldsh r1, [r0, r2]
	lsls r1, r1, #0x03
	adds r1, r1, r5
	adds r0, r4, #0x0
	adds r0, #0x1C
	adds r0, r1, r0
	ldr r2, [r0, #0x00]
	adds r1, r1, r4
	movs r7, #0x20
	ldsh r3, [r1, r7]
	movs r7, #0x22
	ldsh r0, [r1, r7]
	str r0, [sp, #0x000]
	ldr r0, _08102A74 @ =0x02035C00
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x004]
	adds r4, r5, r4
	movs r1, #0x12
	ldsh r0, [r4, r1]
	str r0, [sp, #0x008]
	movs r7, #0x14
	ldsh r0, [r4, r7]
	str r0, [sp, #0x00C]
	movs r0, #0x0C
	movs r1, #0x08
	bl func_081028F8
_08102A44:
	adds r5, #0x3C
	movs r0, #0xC0
	add r9, r0
	adds r6, #0x01
	cmp r6, #0x03
	ble _081029C2
	ldr r0, _08102A74 @ =0x02035C00
	ldr r1, [r0, #0x00]
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x02
	bl LoadBgMap
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08102A70: .4byte 0x040000D4
_08102A74: .4byte 0x02035C00
_08102A78: .4byte 0x81000280
_08102A7C: .4byte 0x02035B18
_08102A80: .4byte 0x02035B08
_08102A84: .4byte 0x02035B1A
_08102A88: .4byte 0x09993760
_08102A8C: .4byte 0x09A18EBC
_08102A90: .4byte 0x099931E4
.syntax divided
