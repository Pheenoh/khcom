.syntax unified
	.align 2, 0
	.global func_0800685C
	.thumb
	.thumb_func
	.type func_0800685C, %function
func_0800685C: @ 0800685C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x024
	adds r7, r0, #0x0
	adds r5, r1, #0x0
	adds r1, r2, #0x0
	mov r8, r3
	ldr r2, [sp, #0x03C]
	ldr r3, [sp, #0x040]
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _080068CC @ =0x02034040
	ldr r4, [r0, #0x00]
	ldrh r0, [r4, #0x10]
	lsls r0, r0, #0x0A
	str r0, [sp, #0x000]
	ldrh r0, [r4, #0x12]
	lsls r0, r0, #0x0A
	str r0, [sp, #0x004]
	mov r0, sp
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	negs r2, r2
	strh r2, [r0, #0x08]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	negs r3, r3
	strh r3, [r0, #0x0A]
	mov r6, sp
	movs r4, #0x80
	lsls r4, r4, #0x09
	adds r0, r4, #0x0
	bl __divsi3
	strh r0, [r6, #0x0C]
	mov r6, sp
	adds r0, r4, #0x0
	mov r1, r8
	bl __divsi3
	strh r0, [r6, #0x0E]
	mov r0, sp
	negs r5, r5
	lsls r5, r5, #0x08
	strh r5, [r0, #0x10]
	add r4, sp, #0x014
	adds r1, r4, #0x0
	movs r2, #0x01
	bl func_08117FE0
	cmp r7, #0x02
	beq _080068D0
	cmp r7, #0x03
	beq _0800690C
	b _08006930
_080068CC: .4byte 0x02034040
_080068D0:
	ldr r1, _080068F4 @ =0x03007510
	ldrh r0, [r4, #0x00]
	strh r0, [r1, #0x00]
	ldr r1, _080068F8 @ =0x030074F8
	ldrh r0, [r4, #0x02]
	strh r0, [r1, #0x00]
	ldr r1, _080068FC @ =0x03007514
	ldrh r0, [r4, #0x04]
	strh r0, [r1, #0x00]
	ldr r1, _08006900 @ =0x0300754C
	ldrh r0, [r4, #0x06]
	strh r0, [r1, #0x00]
	ldr r1, _08006904 @ =0x0300752C
	ldr r0, [r4, #0x08]
	str r0, [r1, #0x00]
	ldr r1, _08006908 @ =0x030074F4
	b _0800692C
	.byte 0x00, 0x00
_080068F4: .4byte 0x03007510
_080068F8: .4byte 0x030074F8
_080068FC: .4byte 0x03007514
_08006900: .4byte 0x0300754C
_08006904: .4byte 0x0300752C
_08006908: .4byte 0x030074F4
_0800690C:
	ldr r1, _0800693C @ =0x030074E8
	ldrh r0, [r4, #0x00]
	strh r0, [r1, #0x00]
	ldr r1, _08006940 @ =0x030074E0
	ldrh r0, [r4, #0x02]
	strh r0, [r1, #0x00]
	ldr r1, _08006944 @ =0x03007504
	ldrh r0, [r4, #0x04]
	strh r0, [r1, #0x00]
	ldr r1, _08006948 @ =0x03007540
	ldrh r0, [r4, #0x06]
	strh r0, [r1, #0x00]
	ldr r1, _0800694C @ =0x03007524
	ldr r0, [r4, #0x08]
	str r0, [r1, #0x00]
	ldr r1, _08006950 @ =0x03007560
_0800692C:
	ldr r0, [r4, #0x0C]
	str r0, [r1, #0x00]
_08006930:
	add sp, #0x024
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0800693C: .4byte 0x030074E8
_08006940: .4byte 0x030074E0
_08006944: .4byte 0x03007504
_08006948: .4byte 0x03007540
_0800694C: .4byte 0x03007524
_08006950: .4byte 0x03007560
.syntax divided
