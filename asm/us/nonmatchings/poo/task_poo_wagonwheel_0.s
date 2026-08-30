.syntax unified
	.align 2, 0
	.global task_poo_wagonwheel_0
	.thumb
	.thumb_func
	.type task_poo_wagonwheel_0, %function
task_poo_wagonwheel_0: @ 080D06D4
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r7, r0, #0x0
	movs r0, #0x06
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D0700
	movs r0, #0xAA
	lsls r0, r0, #0x0A
	str r0, [r7, #0x24]
	ldr r0, _080D06F8 @ =0x00018D00
	str r0, [r7, #0x28]
	movs r0, #0x02
	strh r0, [r7, #0x36]
	ldr r0, _080D06FC @ =0x09758B9C
	b _080D0724
_080D06F8: .4byte 0x00018D00
_080D06FC: .4byte 0x09758B9C
_080D0700:
	mov r4, sp
	adds r4, #0x02
	mov r0, sp
	adds r1, r4, #0x0
	bl func_080D2CF4
	mov r0, sp
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x08
	str r0, [r7, #0x24]
	movs r1, #0x00
	ldsh r0, [r4, r1]
	lsls r0, r0, #0x08
	str r0, [r7, #0x28]
	movs r0, #0x04
	strh r0, [r7, #0x36]
	ldr r0, _080D0764 @ =0x09758BF4
_080D0724:
	str r0, [r7, #0x08]
	ldr r0, [r7, #0x24]
	str r0, [r7, #0x3C]
	movs r4, #0x00
	str r4, [r7, #0x2C]
	str r4, [r7, #0x30]
	movs r6, #0x00
	movs r0, #0xC0
	lsls r0, r0, #0x01
	strh r0, [r7, #0x34]
	str r4, [r7, #0x04]
	adds r5, r7, #0x0
	adds r5, #0x0C
	ldr r1, _080D0768 @ =0x09EF60AC
	ldr r2, _080D076C @ =0x09EF6078
	adds r0, r5, #0x0
	bl func_08005968
	ldrh r1, [r7, #0x36]
	adds r0, r5, #0x0
	movs r2, #0x01
	bl func_080059A4
	str r4, [r7, #0x38]
	adds r0, r7, #0x0
	adds r0, #0x40
	strb r6, [r0, #0x00]
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D0764: .4byte 0x09758BF4
_080D0768: .4byte 0x09EF60AC
_080D076C: .4byte 0x09EF6078
.syntax divided
