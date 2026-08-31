.syntax unified
	.align 2, 0
	.global task_bos_boogie_knife_0
	.thumb
	.thumb_func
	.type task_bos_boogie_knife_0, %function
task_bos_boogie_knife_0: @ 080DB0DC
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0x0
	mov r9, r1
	movs r0, #0x00
	str r0, [r5, #0x00]
	strh r0, [r5, #0x04]
	ldr r0, _080DB100 @ =0x0203C578
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080DB104
	movs r0, #0xA0
	lsls r0, r0, #0x01
	adds r1, r5, r0
	subs r0, #0x0D
	b _080DB10C
_080DB100: .4byte 0x0203C578
_080DB104:
	movs r2, #0xA0
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldr r0, _080DB15C @ =0xFFFFFECD
_080DB10C:
	str r0, [r1, #0x00]
	movs r0, #0x9E
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r0, #0x00
	str r0, [r1, #0x00]
	movs r1, #0xA8
	lsls r1, r1, #0x01
	adds r6, r5, r1
	movs r0, #0x42
	str r0, [r6, #0x00]
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r2, r2, r5
	mov r8, r2
	ldr r0, _080DB160 @ =0xFFFFFB00
	str r0, [r2, #0x00]
	ldr r0, _080DB164 @ =0x0203C55C
	ldr r4, [r0, #0x00]
	movs r0, #0x2E
	ldsh r7, [r4, r0]
	adds r0, r7, #0x0
	movs r1, #0x03
	bl __divsi3
	movs r2, #0x2C
	ldsh r1, [r4, r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bge _080DB16C
	ldr r0, [r6, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x08
	asrs r1, r1, #0x08
	str r1, [r6, #0x00]
	ldr r0, _080DB168 @ =0xFFFFF600
	b _080DB186
	.byte 0x00, 0x00
_080DB15C: .4byte 0xFFFFFECD
_080DB160: .4byte 0xFFFFFB00
_080DB164: .4byte 0x0203C55C
_080DB168: .4byte 0xFFFFF600
_080DB16C:
	movs r2, #0x2C
	ldsh r4, [r4, r2]
	lsls r0, r7, #0x01
	movs r1, #0x03
	bl __divsi3
	cmp r4, r0
	bge _080DB18A
	ldr r0, [r6, #0x00]
	lsls r0, r0, #0x09
	asrs r0, r0, #0x08
	str r0, [r6, #0x00]
	ldr r0, _080DB1F0 @ =0xFFFFF880
_080DB186:
	mov r1, r8
	str r0, [r1, #0x00]
_080DB18A:
	movs r0, #0x97
	lsls r0, r0, #0x0A
	str r0, [r5, #0x34]
	ldr r0, _080DB1F4 @ =0xFFFF4000
	str r0, [r5, #0x38]
	mov r2, r9
	ldr r0, [r2, #0x00]
	str r0, [r5, #0x30]
	adds r0, r5, #0x0
	adds r0, #0x6C
	ldr r1, _080DB1F8 @ =0x096FE0C0
	ldrh r2, [r1, #0x08]
	ldrh r3, [r1, #0x06]
	movs r1, #0x08
	bl func_080122AC
	ldr r0, _080DB1FC @ =0x0979C44E
	movs r1, #0xC4
	lsls r1, r1, #0x04
	bl LoadObjTiles
	str r0, [r5, #0x08]
	ldr r0, _080DB200 @ =0x0984AFD8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x0C]
	ldr r0, _080DB204 @ =0x08F69BC4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x10]
	adds r4, r5, #0x0
	adds r4, #0x14
	ldr r1, _080DB208 @ =0x09EF684C
	ldr r2, _080DB20C @ =0x09EF6848
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DB1F0: .4byte 0xFFFFF880
_080DB1F4: .4byte 0xFFFF4000
_080DB1F8: .4byte 0x096FE0C0
_080DB1FC: .4byte 0x0979C44E
_080DB200: .4byte 0x0984AFD8
_080DB204: .4byte 0x08F69BC4
_080DB208: .4byte 0x09EF684C
_080DB20C: .4byte 0x09EF6848
.syntax divided
