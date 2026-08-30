.syntax unified
	.align 2, 0
	.global func_08005690
	.thumb
	.thumb_func
	.type func_08005690, %function
func_08005690: @ 08005690
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x024
	adds r7, r0, #0x0
	adds r4, r1, #0x0
	adds r1, r2, #0x0
	mov r8, r3
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0x00
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	mov r2, sp
	movs r0, #0x78
	strh r0, [r2, #0x08]
	movs r0, #0x50
	strh r0, [r2, #0x0A]
	mov r6, sp
	movs r5, #0x80
	lsls r5, r5, #0x09
	adds r0, r5, #0x0
	bl func_0811D5EC
	strh r0, [r6, #0x0C]
	mov r6, sp
	adds r0, r5, #0x0
	mov r1, r8
	bl func_0811D5EC
	strh r0, [r6, #0x0E]
	mov r0, sp
	negs r4, r4
	lsls r4, r4, #0x08
	strh r4, [r0, #0x10]
	add r4, sp, #0x014
	adds r1, r4, #0x0
	movs r2, #0x01
	bl func_08117FE0
	cmp r7, #0x02
	beq _080056EA
	cmp r7, #0x03
	beq _08005728
	b _08005754
_080056EA:
	ldr r1, _08005710 @ =0x03007510
	ldrh r0, [r4, #0x00]
	strh r0, [r1, #0x00]
	ldr r1, _08005714 @ =0x030074F8
	ldrh r0, [r4, #0x02]
	strh r0, [r1, #0x00]
	ldr r1, _08005718 @ =0x03007514
	ldrh r0, [r4, #0x04]
	strh r0, [r1, #0x00]
	ldr r1, _0800571C @ =0x0300754C
	ldrh r0, [r4, #0x06]
	strh r0, [r1, #0x00]
	ldr r1, _08005720 @ =0x0300752C
	ldr r0, [r4, #0x08]
	ldr r2, [sp, #0x03C]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	ldr r1, _08005724 @ =0x030074F4
	b _0800574C
_08005710: .4byte 0x03007510
_08005714: .4byte 0x030074F8
_08005718: .4byte 0x03007514
_0800571C: .4byte 0x0300754C
_08005720: .4byte 0x0300752C
_08005724: .4byte 0x030074F4
_08005728:
	ldr r1, _08005760 @ =0x030074E8
	ldrh r0, [r4, #0x00]
	strh r0, [r1, #0x00]
	ldr r1, _08005764 @ =0x030074E0
	ldrh r0, [r4, #0x02]
	strh r0, [r1, #0x00]
	ldr r1, _08005768 @ =0x03007504
	ldrh r0, [r4, #0x04]
	strh r0, [r1, #0x00]
	ldr r1, _0800576C @ =0x03007540
	ldrh r0, [r4, #0x06]
	strh r0, [r1, #0x00]
	ldr r1, _08005770 @ =0x03007524
	ldr r0, [r4, #0x08]
	ldr r2, [sp, #0x03C]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	ldr r1, _08005774 @ =0x03007560
_0800574C:
	ldr r0, [r4, #0x0C]
	ldr r2, [sp, #0x040]
	adds r0, r0, r2
	str r0, [r1, #0x00]
_08005754:
	add sp, #0x024
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08005760: .4byte 0x030074E8
_08005764: .4byte 0x030074E0
_08005768: .4byte 0x03007504
_0800576C: .4byte 0x03007540
_08005770: .4byte 0x03007524
_08005774: .4byte 0x03007560
.syntax divided
