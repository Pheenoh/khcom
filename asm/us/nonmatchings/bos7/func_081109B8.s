.syntax unified
	.align 2, 0
	.global func_081109B8
	.thumb
	.thumb_func
	.type func_081109B8, %function
func_081109B8: @ 081109B8
	push {r4, r5, r6, lr}
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r4, [r0, #0x04]
	movs r5, #0x00
	movs r1, #0xE2
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	bl func_08111660
	movs r1, #0xE4
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	bl func_08111660
	movs r1, #0xE6
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	bl func_08111660
	strh r5, [r4, #0x12]
	ldrh r0, [r4, #0x02]
	subs r0, #0x05
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	bhi _081109F8
	movs r0, #0x00
	b _08110A32
_081109F8:
	cmp r6, #0x01
	bne _08110A24
	movs r1, #0x10
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	bne _08110A24
	adds r0, r4, #0x0
	adds r0, #0xCC
	strh r5, [r0, #0x00]
	subs r0, #0x2C
	movs r1, #0x01
	bl func_0801C2DC
	adds r0, r4, #0x0
	movs r1, #0x00
	bl func_081108AC
	adds r0, r4, #0x0
	movs r1, #0x00
	bl func_081108AC
	movs r5, #0x01
_08110A24:
	movs r1, #0x00
	movs r0, #0x07
	strh r0, [r4, #0x02]
	strh r1, [r4, #0x04]
	strh r1, [r4, #0x06]
	strh r1, [r4, #0x08]
	adds r0, r5, #0x0
_08110A32:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
